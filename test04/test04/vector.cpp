/*
开发者：Wang
功能：vector容器的插入删除以及各类函数
版本：V1.0.0
时间：8:43 2022/7/19
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void vectorTest()
{
	unsigned i;
	int num;
	vector<int> number;
	cout << "请输入将要插入的数：";
	while (1)
	{
		cin >> num;
		number.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	cout << "删除前：" << endl;
	for (i = 0; i < number.size(); i++)
	{
		cout << number[i] << endl;
	}
	cout << "删除最后面的数后：" << endl;
	number.pop_back();
	for (i = 0; i < number.size(); i++)
	{
		cout << number[i] << endl;
	}
	cout << "删除最前面的数后：" << endl;
	

	vector<int>::iterator theIterator = number.begin();
	number.erase(number.begin());

	for (theIterator = number.begin(); theIterator != number.end(); theIterator++)
		cout << *theIterator << endl;;

	/*for (i = 0; i < number.size(); i++)
	{
		cout << number[i] << endl;
	}*/



}