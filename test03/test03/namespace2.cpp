#include <iostream>
using namespace std;
//Ƕ�������ռ�

namespace first_space
{
	void fun()
	{
		cout << "first space" << endl;
	}
	namespace second_space
	{
		void fun()
		{
			cout << "second space" << endl;
		}
	}
}
using namespace first_space::second_space;
int main()
{
	fun();
	return 0;
}