#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m;
void proc1(int a)
{
	m.lock();
	cout << "proc1�������ڸ�дa" << endl;
	cout << "ԭʼaΪ" << a << endl;
	cout << "����aΪ" << a + 2 << endl;
	m.unlock();
}

void proc2(int a)
{
	m.lock();
	cout << "proc2�������ڸ�дa" << endl;
	cout << "ԭʼaΪ" << a << endl;
	cout << "����aΪ" << a + 1 << endl;
	m.unlock();
}

void mutexThreadTest()
{
	int a = 0;
	thread th1(proc1, a);
	thread th2(proc2, a);
	th1.join();
	th2.join();
}