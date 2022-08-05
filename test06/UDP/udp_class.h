#pragma once
#include <winsock2.h>
#pragma comment (lib,"ws2_32.lib")

class Udp
{
public:
	//���캯����ʼ��
	Udp();
	//��������
	~Udp();

	/*
		�������ƣ�SendData
		������ipDest����ip��ַ��buf�Ǵ洢Ҫ�����������飬lenΪ����ĳ���
		���أ�ture�ɹ���falseʧ��
		���ܣ���������
	*/
	bool SendData(const char* ipDest, const char* buf, int len);

	/*
		�������ƣ�RecvData
		������buf�Ǵ洢���ܵ����ݣ�bufsize�Ǵ洢���ݵĴ�С
		���أ�ture�ɹ���falseʧ��
		���ܣ���������
	*/
	bool RecvData(char* buf, int bufsize);

private:
	SOCKET UdpSocket;//udp�׽���
};