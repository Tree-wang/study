#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;
void proc1(int a)
{
	lock_guard<mutex> g1(m);
	cout << "proc1�������ڸ�дa" << endl;
	cout << "ԭʼaΪ��" << a << endl;
	cout << "����aΪ��" << a + 2 << endl;

}
void proc2(int a)

{
	{
		lock_guard<mutex> g2(m);
		cout << "proc2�������ڸ�д" << endl;
		cout << "ԭʼaΪ��" << a << endl;
		cout << "����aΪ��" << a + 1 << endl;
	}
	cout << "�������������3" << endl;
	cout << "�������������4" << endl;
	cout << "�������������5" << endl;
}

int main()
{
	int a = 0;
	thread t1(proc1, a);
	thread t2(proc2, a);
	t1.join();
	t2.join();
	return 0;
}