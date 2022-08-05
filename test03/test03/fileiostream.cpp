#include <iostream>
#include <fstream>
using namespace std;
//创立一个输出文件，向他写入数据，然后关闭文件；再按输入模式打开它，并读取信息。

int main()
{
	string s,str1;
	cout << "请输入文件名:";
	cin >> s;
	ofstream fout("s", ios::out);//定义输出文件流对象fout，打开输出文件f2.dat

	if (!fout)
	{
		cout << "Cannot open output file.\n";
		return 1;
	}
	cout << "要写入的信息：";
	cin >> str1;
	fout << str1 << endl;//把一个十进制整数和十六进制整数写到磁盘文件f2.dat中
	fout.close();

	ifstream fin("s", ios::in);
	if (!fin)
	{
		cout << "Cannot open input file.\n";
		return 1;
	}
	char str[50];
	while (fin)
	{
		fin.getline(str, 50);
		cout << str << endl;
	}
	fin.close();
	return 0;


}