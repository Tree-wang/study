/*
�����ߣ�Wang
���ܣ��̳к����� exception ���������µ��쳣
�汾��V1.0.0
ʱ�䣺15:40 2022/7/18
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
		cout << "���" << endl;
	}
}

