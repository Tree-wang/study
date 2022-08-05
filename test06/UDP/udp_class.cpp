#include <iostream>
#include "udp_class.h"

//���캯��
Udp::Udp()
{
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(1, 1), &wsadata))
	{
		std::cout << "�׽��ִ�ʧ��" << std::endl;
	}
	UdpSocket = socket(AF_INET,     //ͨ��Э���Э���壬��TCP/IPЭ���壬�ò�������ΪAF_INET
		               SOCK_DGRAM,  //udp�׽�������Ϊ���ݱ��׽���
		               IPPROTO_UDP  //udpͨ��Э��           
	                   );
		SOCKADDR_IN addr1;
		addr1.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
		addr1.sin_port = htons(8011);
		addr1.sin_family = AF_INET;

		if (0 != bind(UdpSocket, (SOCKADDR*)&addr1, sizeof(SOCKADDR)))
		{
			std::cout << "bind failed..." << std::endl;
		}

}

//��������
Udp::~Udp()
{
	closesocket(UdpSocket);
	WSACleanup();
}

/*
	�������ƣ�SendData
	������ipDest����ip��ַ��buf�Ǵ洢Ҫ�����������飬lenΪ����ĳ���
	���أ�ture�ɹ���falseʧ��
	���ܣ���������
*/
bool Udp:: SendData(const char* ipDest, const char* buf, int len)
{
	SOCKADDR_IN destaddr;
	destaddr.sin_addr.S_un.S_addr = inet_addr(ipDest);
	destaddr.sin_port = htons(8011);
	destaddr.sin_family = AF_INET;
	if (0 != sendto(UdpSocket, buf, len, 0, (SOCKADDR*)&destaddr, sizeof(SOCKADDR)))
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
	������buf�Ǵ洢���ܵ����ݣ�bufsize�Ǵ洢���ݵĴ�С
	���أ�ture�ɹ���falseʧ��
	���ܣ���������
*/
bool Udp:: RecvData(char* buf, int bufsize)
{
	SOCKADDR_IN fromaddr;
	int length = sizeof(SOCKADDR);
	if (0 != recvfrom(UdpSocket, buf, bufsize,0,(SOCKADDR*)&fromaddr,&length))
	{
		return -1;
	}
	else
	{
		return 0;
	}
}