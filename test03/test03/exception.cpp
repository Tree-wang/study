#include <iostream>
using namespace std;
//异常处理
double division(int a, int b)
{
	if (b == 0)
	{
		throw 1;
	}
	return (a / b);
}

int main()
{
	int x = 5;
	int y = 1;
	double z = 0;
	try
	{
		z = division(x, y);
		cout << z << endl;
	}
	catch (int)
	{
		cout << "分母不能为零" << endl;
	}
	return 0;
}