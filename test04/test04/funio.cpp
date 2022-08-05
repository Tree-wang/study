/*
开发者：Wang
功能：流成员函数举例
版本：V1.0.0
时间：14:03 2022/7/18
*/
#include <iostream>
using namespace std;

void funIoTest()
{
	cout << "---------1---------\n";
	cout << "输出123，域宽为10，默认右对齐" << endl;
	cout.width(10);//设置域宽为10位
	cout << 123 << endl;//输出整数123，占10位，默认为右对齐
	cout << "---------2---------\n";
	cout << "输出123，按数据实际长度输出" << endl;
	cout << 123 << endl; 

	cout << "---------3---------\n";
	cout << "输出123，域宽为10，默认右对齐，空白处用'&'填充" << endl;
	cout.fill('&');
	cout.width(10);
	cout << 123 << endl;
	cout << "---------4---------\n";
	cout << "输出123，按数据实际长度输出，左对齐" << endl;
	cout.setf(ios::left);
	cout << 123 << endl;

	cout << "---------5---------\n";
	cout << "输出123.5，以一般十进制小数形式输出，有效数字为4位" << endl;
	cout.precision(4);
	cout << 123.456789 << endl;
	cout << "---------6---------\n";
	cout << "输出123.456789，以fixed形式输出，小数占4位" << endl;
	cout.setf(ios::fixed);
	cout << 123.45678 << endl;
	cout << "---------7---------\n";
	cout << "输出123.45678，以指数格式输出，域宽为10，小数占4位，用'&'填充" << endl;
	cout.width(15);
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout << 123.45678 << endl;
	cout << "---------8---------\n";
	cout << "输出21，以十六进制" << endl;
	int a = 21;
	cout.setf(ios::showbase);
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << a << endl;


}