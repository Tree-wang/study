#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;
void proc1(int a)
{
	lock_guard<mutex> g1(m);
	cout << "proc1函数正在改写a" << endl;
	cout << "原始a为：" << a << endl;
	cout << "现在a为：" << a + 2 << endl;

}
void proc2(int a)

{
	{
		lock_guard<mutex> g2(m);
		cout << "proc2函数正在改写" << endl;
		cout << "原始a为：" << a << endl;
		cout << "现在a为：" << a + 1 << endl;
	}
	cout << "作用域外的内容3" << endl;
	cout << "作用域外的内容4" << endl;
	cout << "作用域外的内容5" << endl;
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