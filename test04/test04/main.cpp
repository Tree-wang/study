#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>


using namespace std;
//文件和流
void funIoTest();//流成员函数举例
void textFileTest();//文本文件读写
void binFileTest();//二进制文件读写
void fileTest();//汇总
//异常处理
void moreExcTest();//多个catch块的异常处理
void triExcTest();//求三角形面积的异常处理
void newExcTest();//定义新的异常
//模板
void funTempTest(); //函数模板和非函数模板的重载
void classTempTest();// 在类模板外定义成员函数
//多线程
void creatThreadTest();// 创建线程
void mutexThreadTest();// 互斥量
void cpThreadTest();// 生产者消费者模型
void ticketTest();
//STL
void vectorTest();// vector的插入和删除
void stackTest(); //使用栈进行进制转换
void dequeTest();// 使用deque产生随机数
void setTest(); //set关联式容器的使用


int main()
{
loop:
	while (1)
	{
		cout << endl;
		cout << '\n';
		cout << "\n";
		system("color 0B");
		cout << "* * * * --- 1.文件和流 --- * * * *" << endl;
		cout << "* * * * --- 2.异常处理 --- * * * *" << endl;
		cout << "* * * * --- 3.模    板 --- * * * *" << endl;
		cout << "* * * * --- 4.多 线 程 --- * * * *" << endl;
		cout << "* * * * --- 5.   STL   --- * * * * " << endl;
		cout << "* * * * --- 0.退    出 --- * * * *" << endl;

		int a;
		cin >> a;

		switch (a)
		{
		case 1:
			system("cls");
			while (1)
			{
				cout << "* * * * --- 1.流成员函数举例 --- * * * *" << endl;
				cout << "* * * * --- 2.文 本文件读 写 --- * * * *" << endl;
				cout << "* * * * --- 3.二进制文件读写 --- * * * *" << endl;
				cout << "* * * * --- 4.汇          总 --- * * * *" << endl;
				cout << "* * * * --- 0.返 回 上 一 级 --- * * * *" << endl;

				int b1;
				cin >> b1;

				switch (b1)
				{
				case 1:
					system("cls");
					funIoTest();
					break;
				case 2:
					system("cls");
					textFileTest();
					break;
				case 3:
					system("cls");
				    binFileTest();
					break;
				case 4:
					system("cls");
					fileTest();
					break;
				case 0:
					goto loop;

				}
			}
			break;
		case 2:
			system("cls");
			while (1)
			{
				cout << "* * * * --- 1.多个catch块的异常处 理 --- * * * *" << endl;
				cout << "* * * * --- 2.求三角形面积的异常处理 --- * * * *" << endl;
				cout << "* * * * --- 3.定  义  新  的  异  常 --- * * * *" << endl;
				cout << "* * * * --- 0.返   回   上   一   级 --- * * * *" << endl;

				int b2;
				cin >> b2;

				switch (b2)
				{
				case 1:
					system("cls");
					moreExcTest();
					break;
				case 2:
					system("cls");
					triExcTest();
					break;
				case 3:
					system("cls");
					newExcTest();
					break;
				case 0:
					goto loop;

				}
			}
			break;
		case 3:
			system("cls");
			while (1)
			{
				cout << "* * * * --- 1.在 类 模板外定义成员 函 数 --- * * * *" << endl;
				cout << "* * * * --- 2.函数模板和非函数模板的重载 --- * * * *" << endl;
				cout << "* * * * --- 0.返    回    上    一    级 --- * * * *" << endl;

				int b3;
				cin >> b3;

				switch (b3)
				{
				case 1:
					system("cls");
					funTempTest();
					break;
				case 2:
					system("cls");
					classTempTest();
					break;
				case 0:
					goto loop;

				}
			}
			break;
		case 4:
			system("cls");
			while (1)
			{
				cout << "* * * * --- 1.创  建   线   程 --- * * * *" << endl;
				cout << "* * * * --- 2.互     斥     量 --- * * * *" << endl;
				cout << "* * * * --- 3.生产者消费者模型 --- * * * *" << endl;
				cout << "* * * * --- 4.火车票售票 问 题 --- * * * *" << endl;
				cout << "* * * * --- 0.返  回 上 一  级 --- * * * *" << endl;

				int b4;
				cin >> b4;

				switch (b4)
				{
				case 1:
					system("cls");
				    creatThreadTest();
					break;
				case 2:
					system("cls");
				    mutexThreadTest();
					break;
				case 3:
					system("cls");
					cpThreadTest();
					break;
				case 4:
					system("cls");
					ticketTest();
					break;
				case 0:
					goto loop;

				}
			}
			break;
		case 5:
			system("cls");
			while (1)
			{
				cout << "* * * * --- 1.vector 的插入和删除 --- * * * *" << endl;
				cout << "* * * * --- 2.使用 栈进行进制转换 --- * * * *" << endl;
				cout << "* * * * --- 3.使用deque产生随机数 --- * * * *" << endl;
				cout << "* * * * --- 4.set关联式容器的使用 --- * * * *" << endl;
				cout << "* * * * --- 0.返  回  上  一   级 --- * * * *" << endl;

				int b5;
				cin >> b5;

				switch (b5)
				{
				case 1:
					system("cls");
					vectorTest();
					break;
				case 2:
					system("cls");
					stackTest();
					break;
				case 3:
					system("cls");
					dequeTest();
					break;
				case 4:
					system("cls");
					setTest();
					break;
				case 0:
					goto loop;

				}
			}
			break;
		case 0:
			exit(1);
		}
	}
	return 0;
}