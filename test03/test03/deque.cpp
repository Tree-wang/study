#include <iostream>
#include <functional>
#include <deque>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int Size = 6;
	unsigned int  i;
	deque<int> nums;
	srand(time(0));
	for (i = 0; i < Size; i++)
	{
		int temp = rand();
		cout << temp << endl;
		nums.push_back(temp);
	}
	cout << "˫�˶��е�ֵ��" << endl;
	deque<int>::iterator it, itend,j;//��������ʽѯ��
	it = nums.begin();
	itend = nums.end();
	for (j = it; j != itend; j++)
	{
		cout << *j << endl;
		
	}
	return 0;
}