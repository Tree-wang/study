#pragma once
#include <winsock2.h>
#pragma comment (lib,"ws2_32.lib")

class Udp
{
public:
	//构造函数初始化
	Udp();
	//析构函数
	~Udp();

	/*
		函数名称：SendData
		参数：ipDest输入ip地址，buf是存储要发送数据数组，len为数组的长度
		返回：ture成功，false失败
		功能：发送数据
	*/
	bool SendData(const char* ipDest, const char* buf, int len);

	/*
		函数名称：RecvData
		参数：buf是存储接受的数据，bufsize是存储数据的大小
		返回：ture成功，false失败
		功能：接收数据
	*/
	bool RecvData(char* buf, int bufsize);

private:
	SOCKET UdpSocket;//udp套接字
};