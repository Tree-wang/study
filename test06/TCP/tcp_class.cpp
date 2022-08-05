#include "tcp_class.h"
#include <iostream>
#include <stdio.h>
#include <process.h>

using namespace std;

//���캯��
TcpServer::TcpServer()
{
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(1, 1), &wsadata))
	{
		cout << "�׽��ִ�ʧ��" << endl;
		return;
	}

	TcpSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(6000);
	addr.sin_family = AF_INET;

	bind(TcpSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR));
	listen(TcpSocket, 5);
}

//��������
TcpServer::~TcpServer()
{
	closesocket(TcpSocket);
	WSACleanup();
}


//����ͻ�������
void TcpServer::handleConnections()
{
	sockaddr_in remoteAddr;
	int nAddrLen = sizeof(remoteAddr);
	SOCKET currentConnection;
	while (1)
	{
		Sleep(500);
		currentConnection = accept(TcpSocket, (SOCKADDR*)&remoteAddr, &nAddrLen);
		_beginthread(handleRequests, 0, (LPVOID)currentConnection);
	}
}
//��������
void TcpServer::handleRequests(LPVOID param)
{
	SOCKET currentConnection = (SOCKET)param;
	char buf[128];
	while (1)
	{
		if (SOCKET_ERROR == recv(currentConnection, buf, 128, 0))
		{
			//������WSAGetLastError��ȡ������󣬲�������Ӧ�Ĵ�����
			//�������Ϳɲο�MSDN

			closesocket(currentConnection);	//�Ͽ�����
		}
		else
		{
			//�Կͻ��˷�����������н���
			//////////////////////////
			if (SOCKET_ERROR == send(currentConnection, "feedback result", 16, 0))
				cout << "���յ���Ϣ����" << endl;
		}
	}
}


//=============================================================
//��ʼ���ͻ���
TcpClient::TcpClient()
{
	WSADATA wsa;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsa))
		throw std::exception("����winsock��̬���ӿ�ʧ�ܣ�");

	TcpSocket = socket(AF_INET,	//ͨ��Э���Э���壬��TCP/IPЭ���壬�ò�������ΪAF_INET
		SOCK_STREAM,	//�׽�������Ϊ������
		IPPROTO_TCP	//ͨ��Э��
	);
	if (TcpSocket == INVALID_SOCKET)
		throw std::exception("��Ч�׽��֣�");

	//���ñ��ص�ַ
	SOCKADDR_IN localAddr;
	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(6000);	//�����˿ں�
	localAddr.sin_addr.s_addr = INADDR_ANY;	//����

	if (0 != bind(TcpSocket, (sockaddr*)&localAddr, sizeof(localAddr)))	//�󶨵�ַ
		throw std::exception("�󶨵�ַʧ�ܣ�");
}

//�ͻ�����������
TcpClient::~TcpClient()
{
	closesocket(TcpSocket);
	WSACleanup();
}

/*
	�������ƣ�Connect
	������ipDest ip��ַ��Ϣ
	���أ�����0�ɹ���-1ʧ��
	���ܣ��ͻ������ӷ�������
*/
long TcpClient::Connect(const char* ipDest)
{
	//��дԶ�̵�ַ��Ϣ
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(6000);
	servAddr.sin_addr.S_un.S_addr = inet_addr(ipDest);
	if (connect(TcpSocket, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

/*
	�������ƣ�SendData
	������buf�Ǵ洢Ҫ�������ݣ�lengthΪ����ĳ���
	���أ�����0�ɹ���-1ʧ��
	���ܣ���������
*/
long TcpClient::SendData(const char* buf, int length)
{
	if (SOCKET_ERROR == send(TcpSocket, buf, length, 0))
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

/*
	�������ƣ�RecvData
	������buf�Ǵ洢Ҫ�����������飬lengthΪ����ĳ���
	���أ�����0�ɹ���-1ʧ��
	���ܣ���������
*/
long TcpClient:: RecvData(char* buf, int length)
{
	if (SOCKET_ERROR == recv(TcpSocket, buf, length, 0))
	{
		return -1;
	}	
	else
	{
		return 0;
	}
		
}