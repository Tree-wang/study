/*
�����ߣ�Wang
���ܣ�vector����
�汾��V1.0.0
ʱ�䣺15:07 2022/7/14
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned i;
	vector <int> number;
	number.insert(number.begin(), 90);
	number.insert(number.begin(), 80);
	number.insert(number.end(), 20);
	number.insert(number.end(), 30);
	for (i = 0; i < number.size(); i++)
	{
		cout << number[i] << endl;
	}
	number.erase(number.begin());
	number.erase(number.end()-1);//����Ϊnumber.erase(number.end());�ᳬ����Χ
	for (i = 0; i < number.size(); i++)
	{
		cout << number[i] << endl;
	}
	return 0;
}

