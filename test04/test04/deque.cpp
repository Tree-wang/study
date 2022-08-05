/*
开发者：Wang
功能：使用deque产生随机数
版本：V1.0.0
时间：8:43 2022/7/19
*/

#include <iostream>
#include <functional>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

void dequeTest()
{
	const int Size = 6;
	unsigned int i;
	deque<int> nums;
	srand(time(0));
	for (i = 0; i < Size; i++)
	{
		int temp = rand();
		cout << temp << endl;
		nums.push_back(temp);
	}

	cout << "双端队列的值：" << endl;

	deque<int>::iterator it, itend;
	it = nums.begin();
	itend = nums.end();
	for (deque<int>::iterator j = it; j != itend; j++)
	{
		cout << *j << endl;
	}
}