/*
开发者：Wang
功能：使用栈进行进制转换
版本：V1.0.0
时间：8:43 2022/7/19
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
	cout << "请输入一个整数:";
	cin >> num;
	cout << num << "的八进制是：";
	while (num)//num不为零
	{
		mystack.push(num % 8);//将num%8进栈
		num = num / 8;//num整除8
	}
	while (!mystack.empty())
	{
		temp = mystack.top();//取栈顶元素
		mystack.pop();//退栈
		cout << temp;
	}
	cout << endl;
	
}