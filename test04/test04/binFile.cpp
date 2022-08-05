/*
开发者：Wang
功能：将a~z 26个英文字母写入二进制文件后，在该文件中读出并显示出来
版本：V1.0.0
时间：14:35 2022/7/18
*/
#include <iostream>
#include <fstream>

using namespace std;

int test_put()
{
	ofstream outf("f3.dat", ios::binary);

	if (!outf)
	{
		cout << "Cannot open output file\n,";
		exit(1);
	}
	char ch = 'a';
	for (int i = 0; i < 26; i++)
	{
		outf.put(ch);
		ch++;
	}
	outf.close();
	return 0;
}

int test_get()
{
	ifstream inf("f3.dat", ios::binary);
	if (!inf)
	{
		cout << "Cannot open input file\n,";
		exit(1);
	}
	char ch;
	while (inf.get(ch))
		cout << ch;
	cout << endl;
	inf.close();
	return 0;
}

void binFileTest()
{
	cout << "将a~z 26个英文字母写入二进制文件后，在该文件中读出并显示出来" << endl;
	test_put();
	test_get();
}