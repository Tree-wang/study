/*
�����ߣ�Wang
���ܣ�vector�����Ĳ���ɾ���Լ����ຯ��
�汾��V1.0.0
ʱ�䣺8:43 2022/7/19
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
	cout << "�����뽫Ҫ���������";
	while (1)
	{
		cin >> num;
		number.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	cout << "ɾ��ǰ��" << endl;
	for (i = 0; i < number.size(); i++)
	{
		cout << number[i] << endl;
	}
	cout << "ɾ������������" << endl;
	number.pop_back();
	for (i = 0; i < number.size(); i++)
	{
		cout << number[i] << endl;
	}
	cout << "ɾ����ǰ�������" << endl;
	

	vector<int>::iterator theIterator = number.begin();
	number.erase(number.begin());

	for (theIterator = number.begin(); theIterator != number.end(); theIterator++)
		cout << *theIterator << endl;;

	/*for (i = 0; i < number.size(); i++)
	{
		cout << number[i] << endl;
	}*/



}