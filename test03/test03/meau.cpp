#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>


using namespace std;
int main()
{
	loop:
	while (1)
	{
		cout << "1.文件和流" << endl;
		cout << "2.异常处理" << endl;
		cout << "3.模板" << endl;
		cout << "4.多线程" << endl;
		cout << "5.STL " << endl;
		cout << "0.退出" << endl;

		int a;
		cin >> a;

		switch (a)
		{
		case 1:
			system("cls");
			while (1)
			{
				cout << "1.流成员函数举例" << endl;
				cout << "2.文本文件读写" << endl;
				cout << "3.二进制文件读写" << endl;
				cout << "0.返回上一级" << endl;

				int b1;
				cin >> b1;

				switch (b1)
				{
				case 1:
					system("cls");
					cout << "流成员函数举例" << endl;
					break;
				case 2:
					system("cls");
					cout << "文本文件读写" << endl;
					break;
				case 3:
					system("cls");
					cout << "二进制文件读写" << endl;
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
				cout << "1.多个catch块的异常处理" << endl;
				cout << "2.求三角形面积的异常处理" << endl;
				cout << "3.定义新的异常" << endl;
				cout << "0.返回上一级" << endl;

				int b2;
				cin >> b2;

				switch (b2)
				{
				case 1:
					system("cls");
					cout << "多个catch块的异常处理" << endl;
					break;
				case 2:
					system("cls");
					cout << "求三角形面积的异常处理" << endl;
					break;
				case 3:
					system("cls");
					cout << "定义新的异常" << endl;
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
				cout << "1.在类模板外定义成员函数" << endl;
				cout << "2.函数模板和非函数模板的重载" << endl;
				cout << "0.返回上一级" << endl;

				int b3;
				cin >> b3;

				switch (b3)
				{
				case 1:
					system("cls");
					cout << "在类模板外定义成员函数" << endl;
					break;
				case 2:
					system("cls");
					cout << ".函数模板和非函数模板的重载" << endl;
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
				cout << "1.创建线程" << endl;
				cout << "2.互斥量" << endl;
				cout << "3.生产者消费者模型" << endl;
				cout << "0.返回上一级" << endl;

				int b4;
				cin >> b4;

				switch (b4)
				{
				case 1:
					system("cls");
					cout << ".创建线程" << endl;
					break;
				case 2:
					system("cls");
					cout << "互斥量" << endl;
					break;
				case 3:
					system("cls");
					cout << ".生产者消费者模型" << endl;
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
				cout << "1.vector的插入和删除" << endl;
				cout << "2.使用栈进行进制转换" << endl;
				cout << "3.使用deque产生随机数" << endl;
				cout << "4.set关联式容器的使用" << endl;
				cout << "0.返回上一级" << endl;

				int b5;
				cin >> b5;

				switch (b5)
				{
				case 1:
					system("cls");
					cout << "vector的插入和删除" << endl;
					break;
				case 2:
					system("cls");
					cout << "使用栈进行进制转换" << endl;
					break;
				case 3:
					system("cls");
					cout << "使用deque产生随机数" << endl;
					break;
				case 4:
					system("cls");
					cout << "set关联式容器的使用" << endl;
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