#include <iostream>
#include <thread>

using namespace std;

void proc(int a)
{
	cout << "�������̣߳��������Ϊ" << a << endl;
	cout << "���߳�����ʾ���߳�idΪ" << this_thread::get_id() << endl;
}
void creatThreadTest()
{
	cout << "�������߳�" << endl;
	int a = 8;
	thread th2(proc, a);
	cout << "���߳�����ʾ���߳�idΪ" << th2.get_id() << endl;
	th2.join();
}