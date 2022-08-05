/*
�����ߣ�Wang
���ܣ�����������������
�汾��V1.0.0
ʱ�䣺8:43 2022/7/19
*/

#include <iostream>
#include <deque>
#include<mutex>
#include <condition_variable>
#include <Windows.h>

using namespace std;

deque<int> q;
mutex mu;
condition_variable cond; 
int c = 0;//��������Ʒ����

void producer()
{
	int data1;
	while (1)//��֤��������ֹͣ
	{
		if (c < 3)//����
		{
			{
				data1 = rand();
				unique_lock<mutex> locker(mu);//��
				q.push_front(data1);
				cout << "����" << data1 << endl;
				cond.notify_one();
				++c;
			}
			Sleep(500);
		}
	}
}

void consumer()
{
	int data2;//data�������Ǵ�ŵ�����
	while (1)
	{
		{
			unique_lock<mutex> locker(mu);
			while (q.empty())
				cond.wait(locker);//wait()���Ƚ����������������߲��ܻ�������ò�Ʒ����������������notify�󣬽��������������Զ��ֻ��������
			data2 = q.back();
			q.pop_back();
			cout << "ȡ��" << data2 << endl;
			--c;
		}
		Sleep(1500);
	}
}

void cpThreadTest()
{
	
		thread t1(producer);
		thread t2(consumer);
		t1.join();
		t2.join();
}
