/*
�����ߣ�Wang
���ܣ�����Ա��������
�汾��V1.0.0
ʱ�䣺14:03 2022/7/18
*/
#include <iostream>
using namespace std;

void funIoTest()
{
	cout << "---------1---------\n";
	cout << "���123�����Ϊ10��Ĭ���Ҷ���" << endl;
	cout.width(10);//�������Ϊ10λ
	cout << 123 << endl;//�������123��ռ10λ��Ĭ��Ϊ�Ҷ���
	cout << "---------2---------\n";
	cout << "���123��������ʵ�ʳ������" << endl;
	cout << 123 << endl; 

	cout << "---------3---------\n";
	cout << "���123�����Ϊ10��Ĭ���Ҷ��룬�հ״���'&'���" << endl;
	cout.fill('&');
	cout.width(10);
	cout << 123 << endl;
	cout << "---------4---------\n";
	cout << "���123��������ʵ�ʳ�������������" << endl;
	cout.setf(ios::left);
	cout << 123 << endl;

	cout << "---------5---------\n";
	cout << "���123.5����һ��ʮ����С����ʽ�������Ч����Ϊ4λ" << endl;
	cout.precision(4);
	cout << 123.456789 << endl;
	cout << "---------6---------\n";
	cout << "���123.456789����fixed��ʽ�����С��ռ4λ" << endl;
	cout.setf(ios::fixed);
	cout << 123.45678 << endl;
	cout << "---------7---------\n";
	cout << "���123.45678����ָ����ʽ��������Ϊ10��С��ռ4λ����'&'���" << endl;
	cout.width(15);
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout << 123.45678 << endl;
	cout << "---------8---------\n";
	cout << "���21����ʮ������" << endl;
	int a = 21;
	cout.setf(ios::showbase);
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << a << endl;


}