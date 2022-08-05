/*
�����ߣ�Wang
���ܣ����������������ʱ���ֵ��쳣���쳣�����߲���Ϊ��������֮�ʹ��ڵ����ߡ�
      �����쳣ʱӦ�ȴ���߲���Ϊ��Ȼ���ٴ�������֮��С�ڵ����ߵ��쳣��
�汾��V1.0.0
ʱ�䣺15:10 2022/7/18
*/
#include <iostream>
using namespace std;

double triarea(int a, int b, int c)
{
	double s = (a + b + c) / 2;
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		throw 1;
	}

	return sqrt(s * (s - a) * (s - b));
}

void triExcTest()
{
	int x;
	int y;
	int z;
	double area;

	try
	{
		cout << "�����������ε������ߣ�" << endl;
		cin >> x >> y >> z;
		if (x <= 0 || y <= 0 || z <= 0)
		{
			throw 1.0;
		}
		if (x > 0 && y > 0 && z > 0)
		{
			area = triarea(x, y, z);
		}
		cout << "�����ε����Ϊ�� " << area << endl;
	}
	catch (int)
	{
		cout << "�����쳣������֮��С�ڵ����ߣ����ܹ���������" << endl;
	}
	catch (double)
	{
		cout << "�����쳣���߲���Ϊ��" << endl;
	}
}