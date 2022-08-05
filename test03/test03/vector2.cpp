/*
开发者：Wang
功能：vector容器中iterator用法
版本：V1.0.0
时间：15:25 2022/7/14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector <int> intVector;
	for (int i = 0; i < 10; i++)
	{
		intVector.push_back(i + 10);
	}
	vector <int>::iterator theIterator = intVector.begin();
	intVector.insert(theIterator, 4, 5);
	for (theIterator = intVector.begin(); theIterator != intVector.end(); ++theIterator)
		cout << *theIterator ;
	return 0;
}