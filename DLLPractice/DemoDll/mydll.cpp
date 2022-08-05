#include "pch.h"
#define BUILD_MYDLL
#include "mydll.h"
#include <iostream>

using namespace std;
int convert_array(int* data, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << data[i] << ",";
	}
	cout << endl;

	int nTotal = 0;
	for (int i = 0; i < len; i++)
	{
		nTotal += data[i];
		--data[i];
	}
	return nTotal;
}
