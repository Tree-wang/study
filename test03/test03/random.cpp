#include <iostream>
#include <random>
#include <thread>
#include "random.h"
#include<Windows.h>
using namespace std;

int main()
{
	while (1)
	{
		cout << rand() << endl;
		Sleep(1000);
	}
	
	return 0;
}