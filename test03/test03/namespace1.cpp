#include <iostream>
using namespace std;

//��һ�������ռ�
namespace first_space
{
	void fun()
	{
		cout << "first space" << endl;
	}
}

//�ڶ��������ռ�
namespace second_space
{
	void fun()
	{
		cout << "second space" << endl;
	}
}

int main()
{
	first_space::fun();//���õ�һ�������ռ���ĺ���
	second_space::fun();//���õڶ��������ռ���ĺ���
	return 0;
}