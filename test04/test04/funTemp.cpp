/*
�����ߣ�Wang
���ܣ�����ģ��ͷǺ���ģ�������
�汾��V1.0.0
ʱ�䣺15:50 2022/7/18
*/

#include <iostream>
#include <conio.h>
using namespace std;

template <typename AT>
AT Min(AT x, AT y)
{
	cout << "����ģ�庯����";
	return (x < y) ? x : y;
}

int Min(int x, int y)
{
	cout << "���÷�ģ�庯����";
	return (x < y) ? x : y;
}

void funTempTest()
{
	int i1, i2;
	double d1, d2;
	char c1, c2;
	cout << "���������������������";
	cin >> i1 >> i2;
	cout << "��С�������ǣ�" << Min(i1, i2) << endl;
	cout << "��������������ȸ�������";
	cin >> d1 >> d2;
	cout << "��С�����������ǣ�" << Min(d1, d2) << endl;
	cout << "����������������ַ���";
	cin >> c1;
	cin.get();
	cin >> c2;
	cout << "��С���ַ��ǣ�" << Min(c1, c2) << endl;

}