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
		cout << "1.�ļ�����" << endl;
		cout << "2.�쳣����" << endl;
		cout << "3.ģ��" << endl;
		cout << "4.���߳�" << endl;
		cout << "5.STL " << endl;
		cout << "0.�˳�" << endl;

		int a;
		cin >> a;

		switch (a)
		{
		case 1:
			system("cls");
			while (1)
			{
				cout << "1.����Ա��������" << endl;
				cout << "2.�ı��ļ���д" << endl;
				cout << "3.�������ļ���д" << endl;
				cout << "0.������һ��" << endl;

				int b1;
				cin >> b1;

				switch (b1)
				{
				case 1:
					system("cls");
					cout << "����Ա��������" << endl;
					break;
				case 2:
					system("cls");
					cout << "�ı��ļ���д" << endl;
					break;
				case 3:
					system("cls");
					cout << "�������ļ���д" << endl;
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
				cout << "1.���catch����쳣����" << endl;
				cout << "2.��������������쳣����" << endl;
				cout << "3.�����µ��쳣" << endl;
				cout << "0.������һ��" << endl;

				int b2;
				cin >> b2;

				switch (b2)
				{
				case 1:
					system("cls");
					cout << "���catch����쳣����" << endl;
					break;
				case 2:
					system("cls");
					cout << "��������������쳣����" << endl;
					break;
				case 3:
					system("cls");
					cout << "�����µ��쳣" << endl;
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
				cout << "1.����ģ���ⶨ���Ա����" << endl;
				cout << "2.����ģ��ͷǺ���ģ�������" << endl;
				cout << "0.������һ��" << endl;

				int b3;
				cin >> b3;

				switch (b3)
				{
				case 1:
					system("cls");
					cout << "����ģ���ⶨ���Ա����" << endl;
					break;
				case 2:
					system("cls");
					cout << ".����ģ��ͷǺ���ģ�������" << endl;
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
				cout << "1.�����߳�" << endl;
				cout << "2.������" << endl;
				cout << "3.������������ģ��" << endl;
				cout << "0.������һ��" << endl;

				int b4;
				cin >> b4;

				switch (b4)
				{
				case 1:
					system("cls");
					cout << ".�����߳�" << endl;
					break;
				case 2:
					system("cls");
					cout << "������" << endl;
					break;
				case 3:
					system("cls");
					cout << ".������������ģ��" << endl;
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
				cout << "1.vector�Ĳ����ɾ��" << endl;
				cout << "2.ʹ��ջ���н���ת��" << endl;
				cout << "3.ʹ��deque���������" << endl;
				cout << "4.set����ʽ������ʹ��" << endl;
				cout << "0.������һ��" << endl;

				int b5;
				cin >> b5;

				switch (b5)
				{
				case 1:
					system("cls");
					cout << "vector�Ĳ����ɾ��" << endl;
					break;
				case 2:
					system("cls");
					cout << "ʹ��ջ���н���ת��" << endl;
					break;
				case 3:
					system("cls");
					cout << "ʹ��deque���������" << endl;
					break;
				case 4:
					system("cls");
					cout << "set����ʽ������ʹ��" << endl;
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