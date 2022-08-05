#include <iostream>
using namespace std;
//Ç¶Ì×ÃüÃû¿Õ¼ä

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