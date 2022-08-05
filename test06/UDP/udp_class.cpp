#include <iostream>
#include "udp_class.h"

//构造函数
Udp::Udp()
{
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(1, 1), &wsadata))
	{
		std::cout << "套接字打开失败" << std::endl;
	}
	UdpSocket = socket(AF_INET,     //通信协议的协议族，对TCP/IP协议族，该参数设置为AF_INET
		               SOCK_DGRAM,  //udp套接字类型为数据报套接字
		               IPPROTO_UDP  //udp通信协议           
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

//析构函数
Udp::~Udp()
{
	closesocket(UdpSocket);
	WSACleanup();
}

/*
	函数名称：SendData
	参数：ipDest输入ip地址，buf是存储要发送数据数组，len为数组的长度
	返回：ture成功，false失败
	功能：发送数据
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
	函数名称：RecvData
	参数：buf是存储接受的数据，bufsize是存储数据的大小
	返回：ture成功，false失败
	功能：接收数据
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