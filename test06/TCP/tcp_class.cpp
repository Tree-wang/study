#include "tcp_class.h"
#include <iostream>
#include <stdio.h>
#include <process.h>

using namespace std;

//构造函数
TcpServer::TcpServer()
{
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(1, 1), &wsadata))
	{
		cout << "套接字打开失败" << endl;
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

//析构函数
TcpServer::~TcpServer()
{
	closesocket(TcpSocket);
	WSACleanup();
}


//处理客户端链接
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
//处理请求
void TcpServer::handleRequests(LPVOID param)
{
	SOCKET currentConnection = (SOCKET)param;
	char buf[128];
	while (1)
	{
		if (SOCKET_ERROR == recv(currentConnection, buf, 128, 0))
		{
			//可利用WSAGetLastError获取具体错误，并进行相应的错误处理
			//错误类型可参考MSDN

			closesocket(currentConnection);	//断开连接
		}
		else
		{
			//对客户端发来的请求进行解析
			//////////////////////////
			if (SOCKET_ERROR == send(currentConnection, "feedback result", 16, 0))
				cout << "接收的消息有误" << endl;
		}
	}
}


//=============================================================
//初始化客户端
TcpClient::TcpClient()
{
	WSADATA wsa;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsa))
		throw std::exception("加载winsock动态链接库失败！");

	TcpSocket = socket(AF_INET,	//通信协议的协议族，对TCP/IP协议族，该参数设置为AF_INET
		SOCK_STREAM,	//套接字类型为数据流
		IPPROTO_TCP	//通信协议
	);
	if (TcpSocket == INVALID_SOCKET)
		throw std::exception("无效套接字！");

	//设置本地地址
	SOCKADDR_IN localAddr;
	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(6000);	//监听端口号
	localAddr.sin_addr.s_addr = INADDR_ANY;	//本机

	if (0 != bind(TcpSocket, (sockaddr*)&localAddr, sizeof(localAddr)))	//绑定地址
		throw std::exception("绑定地址失败！");
}

//客户端析构函数
TcpClient::~TcpClient()
{
	closesocket(TcpSocket);
	WSACleanup();
}

/*
	函数名称：Connect
	参数：ipDest ip地址信息
	返回：返回0成功，-1失败
	功能：客户端链接服务器。
*/
long TcpClient::Connect(const char* ipDest)
{
	//填写远程地址信息
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
	函数名称：SendData
	参数：buf是存储要发送数据，length为数组的长度
	返回：返回0成功，-1失败
	功能：发送数据
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
	函数名称：RecvData
	参数：buf是存储要发送数据数组，length为数组的长度
	返回：返回0成功，-1失败
	功能：接受数据
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