/*
�����ߣ�Wang
���ܣ�ʹ��deque���������
�汾��V1.0.0
ʱ�䣺8:43 2022/7/19
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

	cout << "˫�˶��е�ֵ��" << endl;

	deque<int>::iterator it, itend;
	it = nums.begin();
	itend = nums.end();
	for (deque<int>::iterator j = it; j != itend; j++)
	{
		cout << *j << endl;
	}
}