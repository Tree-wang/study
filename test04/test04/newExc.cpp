/*
开发者：Wang
功能：继承和重载 exception 类来定义新的异常
版本：V1.0.0
时间：15:40 2022/7/18
*/
#include<iostream>
#include<exception>

using namespace std;
struct MyException : public exception
{
	const char* what() const throw()
	{
		return "C++ Exception";
	}
};
void newExcTest()
{
	try
	{
		throw MyException();
	}
	catch (MyException& e)
	{
		std::cout << "MyException caught" << std::endl;
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		cout << "溢出" << endl;
	}
}

