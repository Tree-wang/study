#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>


using namespace std;
//�ļ�����
void funIoTest();//����Ա��������
void textFileTest();//�ı��ļ���д
void binFileTest();//�������ļ���д
void fileTest();//����
//�쳣����
void moreExcTest();//���catch����쳣����
void triExcTest();//��������������쳣����
void newExcTest();//�����µ��쳣
//ģ��
void funTempTest(); //����ģ��ͷǺ���ģ�������
void classTempTest();// ����ģ���ⶨ���Ա����
//���߳�
void creatThreadTest();// �����߳�
void mutexThreadTest();// ������
void cpThreadTest();// ������������ģ��
void ticketTest();
//STL
void vectorTest();// vector�Ĳ����ɾ��
void stackTest(); //ʹ��ջ���н���ת��
void dequeTest();// ʹ��deque���������
void setTest(); //set����ʽ������ʹ��


int main()
{
loop:
	while (1)
	{
		cout << endl;
		cout << '\n';
		cout << "\n";
		system("color 0B");
		cout << "* * * * --- 1.�ļ����� --- * * * *" << endl;
		cout << "* * * * --- 2.�쳣���� --- * * * *" << endl;
		cout << "* * * * --- 3.ģ    �� --- * * * *" << endl;
		cout << "* * * * --- 4.�� �� �� --- * * * *" << endl;
		cout << "* * * * --- 5.   STL   --- * * * * " << endl;
		cout << "* * * * --- 0.��    �� --- * * * *" << endl;

		int a;
		cin >> a;

		switch (a)
		{
		case 1:
			system("cls");
			while (1)
			{
				cout << "* * * * --- 1.����Ա�������� --- * * * *" << endl;
				cout << "* * * * --- 2.�� ���ļ��� д --- * * * *" << endl;
				cout << "* * * * --- 3.�������ļ���д --- * * * *" << endl;
				cout << "* * * * --- 4.��          �� --- * * * *" << endl;
				cout << "* * * * --- 0.�� �� �� һ �� --- * * * *" << endl;

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
				cout << "* * * * --- 1.���catch����쳣�� �� --- * * * *" << endl;
				cout << "* * * * --- 2.��������������쳣���� --- * * * *" << endl;
				cout << "* * * * --- 3.��  ��  ��  ��  ��  �� --- * * * *" << endl;
				cout << "* * * * --- 0.��   ��   ��   һ   �� --- * * * *" << endl;

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
				cout << "* * * * --- 1.�� �� ģ���ⶨ���Ա �� �� --- * * * *" << endl;
				cout << "* * * * --- 2.����ģ��ͷǺ���ģ������� --- * * * *" << endl;
				cout << "* * * * --- 0.��    ��    ��    һ    �� --- * * * *" << endl;

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
				cout << "* * * * --- 1.��  ��   ��   �� --- * * * *" << endl;
				cout << "* * * * --- 2.��     ��     �� --- * * * *" << endl;
				cout << "* * * * --- 3.������������ģ�� --- * * * *" << endl;
				cout << "* * * * --- 4.��Ʊ��Ʊ �� �� --- * * * *" << endl;
				cout << "* * * * --- 0.��  �� �� һ  �� --- * * * *" << endl;

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
				cout << "* * * * --- 1.vector �Ĳ����ɾ�� --- * * * *" << endl;
				cout << "* * * * --- 2.ʹ�� ջ���н���ת�� --- * * * *" << endl;
				cout << "* * * * --- 3.ʹ��deque��������� --- * * * *" << endl;
				cout << "* * * * --- 4.set����ʽ������ʹ�� --- * * * *" << endl;
				cout << "* * * * --- 0.��  ��  ��  һ   �� --- * * * *" << endl;

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