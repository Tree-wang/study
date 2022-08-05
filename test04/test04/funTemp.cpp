/*
开发者：Wang
功能：函数模板和非函数模板的重载
版本：V1.0.0
时间：15:50 2022/7/18
*/

#include <iostream>
#include <conio.h>
using namespace std;

template <typename AT>
AT Min(AT x, AT y)
{
	cout << "调用模板函数：";
	return (x < y) ? x : y;
}

int Min(int x, int y)
{
	cout << "调用非模板函数：";
	return (x < y) ? x : y;
}

void funTempTest()
{
	int i1, i2;
	double d1, d2;
	char c1, c2;
	cout << "请输入两个不相等整数：";
	cin >> i1 >> i2;
	cout << "较小的整数是：" << Min(i1, i2) << endl;
	cout << "请输入两个不相等浮点数：";
	cin >> d1 >> d2;
	cout << "较小的整浮点数是：" << Min(d1, d2) << endl;
	cout << "请输入两个不相等字符：";
	cin >> c1;
	cin.get();
	cin >> c2;
	cout << "较小的字符是：" << Min(c1, c2) << endl;

}