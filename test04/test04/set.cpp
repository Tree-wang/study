/*
�����ߣ�Wang
���ܣ�set����ʽ������ʹ��
�汾��V1.0.0
ʱ�䣺11:35 2022/7/19
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