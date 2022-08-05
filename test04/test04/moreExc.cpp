/*
开发者：Wang
功能：多个catch块的异常处理程序
版本：V1.0.0
时间：14:40 2022/7/18
*/

#include <iostream>
using namespace std;

void moreExcTest()
{
	int a1 ;
	cout << "请输入数据" << endl;
	cin >> a1;
	try
	{
		throw a1;
	}
	catch (int)
	{
		cout << "异常发生！整数型！" << endl;
	}
	catch (double)
	{
		cout << "异常发生！双精度型！" << endl;
	}
	cout << "end" << endl;
}
