/*
开发者：Wang
功能：set关联式容器的使用
版本：V1.0.0
时间：11:35 2022/7/19
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

void setTest()
{
	set<string> s;
	s.insert("linxiaocha");
	s.insert("chenweixing");
	s.insert("gaoying");
	s.insert("chenweixing");
	set<string>::iterator myit;
	for (myit = s.begin(); myit != s.end(); ++myit)
	{
		cout << *myit << endl;
	}
	cout << endl;
}