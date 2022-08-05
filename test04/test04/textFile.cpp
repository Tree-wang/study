/*
开发者：Wang
功能：创立一个输出文件，向他写入数据，然后关闭文件；再按输入模式打开它，并读取信息。
版本：V1.0.0
时间：13:42 2022/7/18
*/
#include <iostream>
#include <fstream>
using namespace std;
//创立一个输出文件，向他写入数据，然后关闭文件；再按输入模式打开它，并读取信息。

void textFileTest() 
{
	ofstream fout("f2.dat", ios::out);//定义输出文件流对象fout，打开输出文件f2.dat

	if (!fout)
	{
		cout << "Cannot open output file.\n";
		exit(1);
	}
	fout << 100 << ' ' << hex << 100 << endl;//把一个十进制整数和十六进制整数写到磁盘文件f2.dat中
	cout << "把100按十进制和十六进制写到磁盘文件f2.dat中......." << endl;
	cout<<"把字符串\"Hello!\"写入磁盘中......"<<endl;
	fout << "\"Hello!\"\n";
	fout.close();

	ifstream fin("f2.dat", ios::in);
	if (!fin)
	{
		cout << "Cannot open input file.\n";
		exit(1);
	}
	char str[50];
	while (fin)
	{
		fin.getline(str, 50);
		cout << str << endl;
	}
	fin.close();
}