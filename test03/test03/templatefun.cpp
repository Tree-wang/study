/*
�����ߣ�Wang
���ܣ�����ģ��ͷǺ���ģ�������
�汾��V1.0.0
ʱ�䣺10:12 2022/7/14
*/
#include <iostream>
using namespace std;

template <typename T>
T Min(T a, T b)
{
	cout << "����ģ�庯��: ";
	return (a < b) ? a : b;
}

int Min(int a, int b)
{
	cout << "���÷�ģ�庯����";
	return (a < b) ? a : b;
}

int main()
{
	int x = 1, y = 2;
	cout << "��С����Ϊ��" << Min(x, y) << endl;
	double x1 = 1.0, y1 = 2.0;
	cout << "��С����Ϊ��" << Min(x1, y1) << endl;
	return 0;
}
