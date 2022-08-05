#include <iostream>
using namespace std;

//�˳�����Ϊ�˴��������������ʱ���ֵ��쳣��
//�쳣�����߲���Ϊ��������֮�ʹ��ڵ����ߡ������쳣ʱӦ�ȴ���߲���Ϊ��Ȼ���ٴ�������֮��С�ڵ����ߵ��쳣��
double triarea(int a, int b, int c)
{
	double s = (a + b + c) / 2;
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		throw 1;
	}
	
	return sqrt(s * (s - a) * (s - b));
}

int main()
{
	int x;
	int y;
	int z;
	double area;
	
	try 
	{
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
	catch(int)
	{
		cout << "����֮��С�ڵ����ߣ����ܹ���������" << endl;
	}
	catch (double)
	{
		cout << "�߲���Ϊ��" << endl;
	}
	return 0;
}