#include <iostream>
#include <fstream>
using namespace std;
//����һ������ļ�������д�����ݣ�Ȼ��ر��ļ����ٰ�����ģʽ����������ȡ��Ϣ��

int main()
{
	string s,str1;
	cout << "�������ļ���:";
	cin >> s;
	ofstream fout("s", ios::out);//��������ļ�������fout��������ļ�f2.dat

	if (!fout)
	{
		cout << "Cannot open output file.\n";
		return 1;
	}
	cout << "Ҫд�����Ϣ��";
	cin >> str1;
	fout << str1 << endl;//��һ��ʮ����������ʮ����������д�������ļ�f2.dat��
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