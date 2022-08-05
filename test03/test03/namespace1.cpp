#include <iostream>
using namespace std;

//第一个命名空间
namespace first_space
{
	void fun()
	{
		cout << "first space" << endl;
	}
}

//第二个命名空间
namespace second_space
{
	void fun()
	{
		cout << "second space" << endl;
	}
}

int main()
{
	first_space::fun();//调用第一个命名空间里的函数
	second_space::fun();//调用第二个命名空间里的函数
	return 0;
}