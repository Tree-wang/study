/*
�����ߣ�Wang
���ܣ����catch����쳣�������
�汾��V1.0.0
ʱ�䣺14:40 2022/7/18
*/

#include <iostream>
using namespace std;

void moreExcTest()
{
	int a1 ;
	cout << "����������" << endl;
	cin >> a1;
	try
	{
		throw a1;
	}
	catch (int)
	{
		cout << "�쳣�����������ͣ�" << endl;
	}
	catch (double)
	{
		cout << "�쳣������˫�����ͣ�" << endl;
	}
	cout << "end" << endl;
}
