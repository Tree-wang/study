/*
开发者：Wang
功能：函数模板和非函数模板的重载
版本：V1.0.0
时间：10:12 2022/7/14
*/
#include <iostream>
using namespace std;

template <typename T>
T Min(T a, T b)
{
	cout << "调用模板函数: ";
	return (a < b) ? a : b;
}

int Min(int a, int b)
{
	cout << "调用非模板函数：";
	return (a < b) ? a : b;
}

int main()
{
	int x = 1, y = 2;
	cout << "最小的数为：" << Min(x, y) << endl;
	double x1 = 1.0, y1 = 2.0;
	cout << "最小的数为：" << Min(x1, y1) << endl;
	return 0;
}
