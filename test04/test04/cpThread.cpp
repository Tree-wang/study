/*
开发者：Wang
功能：生产者消费者问题
版本：V1.0.0
时间：8:43 2022/7/19
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
int c = 0;//缓冲区产品个数

void producer()
{
	int data1;
	while (1)//保证生成永不停止
	{
		if (c < 3)//限流
		{
			{
				data1 = rand();
				unique_lock<mutex> locker(mu);//锁
				q.push_front(data1);
				cout << "存了" << data1 << endl;
				cond.notify_one();
				++c;
			}
			Sleep(500);
		}
	}
}

void consumer()
{
	int data2;//data用来覆盖存放的数据
	while (1)
	{
		{
			unique_lock<mutex> locker(mu);
			while (q.empty())
				cond.wait(locker);//wait()会先解锁，解锁后生产者才能获得锁来访产品到缓冲区；生产者notify后，将不再阻塞，且自动又获得了锁。
			data2 = q.back();
			q.pop_back();
			cout << "取了" << data2 << endl;
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
