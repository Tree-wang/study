#include <iostream>
#include <fstream>
using namespace std;

//��wang.txt�ļ���д�롰����һ�����ˡ����ر��ļ�������ļ����رո��ļ���

int main()
{
	char data[100];
	ofstream fout("wang.txt", ios::out);
	if (!fout)
	{
		cout << "wang.txt�ļ�������" << endl;
		return 1;
	}
	cin >> data;
	fout << data ;
	fout.close();

	ifstream fin("wang.txt", ios::in);
	if (!fin)
	{
		cout << "wang.txt�ļ�������" << endl;
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