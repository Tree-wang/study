#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;//ʵ����m���󣬲�Ҫ���Ϊ�������
void proc1(int a)
{
    m.lock();//�ֶ�����
    lock_guard<mutex> g1(m, adopt_lock);
    cout << "proc1�������ڸ�дa" << endl;
    cout << "ԭʼaΪ" << a << endl;
    cout << "����aΪ" << a + 2 << endl;
}//�Զ�����

void proc2(int a)
{
    lock_guard<mutex> g2(m);//�Զ�����
    cout << "proc2�������ڸ�дa" << endl;
    cout << "ԭʼaΪ" << a << endl;
    cout << "����aΪ" << a + 1 << endl;
}//�Զ�����
int main()
{
    int a = 0;
    thread th1(proc1, a);
    thread th2(proc2, a);
    th1.join();
    th2.join();
    return 0;
}
