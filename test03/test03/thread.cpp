#include<iostream>
#include<thread>
using namespace std;
void proc(int& a)
{
    cout << "�������߳�,�������Ϊ" << a << endl;
    cout << "���߳�����ʾ���߳�idΪ" << this_thread::get_id() << endl;
}

int main()
{
    cout << "�������߳�" << endl;
    int a = 9;
    thread th2(proc,ref(a));
    cout << "���߳�����ʾ���߳�idΪ" << th2.get_id() << endl;
    th2.join();
    return 0;
}