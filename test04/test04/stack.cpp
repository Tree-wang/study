/*
�����ߣ�Wang
���ܣ�ʹ��ջ���н���ת��
�汾��V1.0.0
ʱ�䣺8:43 2022/7/19
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
void stackTest()
{
	int num,temp;
	char c;
	string temp1;
	string s;
	stack<int> mystack;
	stack<string> mystack1;
	cout << "������һ������:";
	cin >> num;
	cout << num << "�İ˽����ǣ�";
	while (num)//num��Ϊ��
	{
		mystack.push(num % 8);//��num%8��ջ
		num = num / 8;//num����8
	}
	while (!mystack.empty())
	{
		temp = mystack.top();//ȡջ��Ԫ��
		mystack.pop();//��ջ
		cout << temp;
	}
	cout << endl;
	
}