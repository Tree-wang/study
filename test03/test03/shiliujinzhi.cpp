#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num, y;
	cin >> num;
	string s;
	char c;
	if (num == 0)
	{
		cout << 0;
	}
	while (num!=0)
	{
		y = num % 16;
		if (y < 10)
		{
			c = y + '0';
		}
		else
			c = y + 'A' - 10;
		s = c + s;
		num /= 16;
	}
	cout << s;
	return 0;
	
}