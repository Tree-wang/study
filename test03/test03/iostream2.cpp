#include <iostream>
#include <fstream>
using namespace std;

//在wang.txt文件中写入“我是一个好人”，关闭文件后读该文件并关闭该文件。

int main()
{
	char data[100];
	ofstream fout("wang.txt", ios::out);
	if (!fout)
	{
		cout << "wang.txt文件不存在" << endl;
		return 1;
	}
	cin >> data;
	fout << data ;
	fout.close();

	ifstream fin("wang.txt", ios::in);
	if (!fin)
	{
		cout << "wang.txt文件不存在" << endl;
		return 1;
	}
	char str[30];
	while (fin)
	{
		fin.getline(str, 20);
		cout << str << endl;
	}
	fin.close();
}