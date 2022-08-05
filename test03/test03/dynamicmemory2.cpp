/*
开发者：Wang
功能：二维数组的动态内存分配
版本：V1.0.0
时间：9:14 2022/7/14 
*/
#include <iostream>
using namespace std;

int main()
{
	int** p;
	int i, j;
	p = new int* [4];
	for (i = 0; i < 4; i++)
	{
		p[i] = new int[8];
	}

	//初始化数组
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 8; j++)
		{
			p[i][j] = i * j;
		}
	}

	//打印数据
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 0) cout << endl;
			cout << p[i][j] << "\t";
		}
	}

	//释放内存
	for (i = 0; i < 4; i++)
	{
		delete [] p[i];
	}
	delete [] p;
	return 0;
}

