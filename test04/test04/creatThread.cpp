#include <iostream>
#include <thread>

using namespace std;

void proc(int a)
{
	cout << "我是子线程，传入参数为" << a << endl;
	cout << "子线程中显示子线程id为" << this_thread::get_id() << endl;
}
void creatThreadTest()
{
	cout << "我是主线程" << endl;
	int a = 8;
	thread th2(proc, a);
	cout << "主线程中显示子线程id为" << th2.get_id() << endl;
	th2.join();
}