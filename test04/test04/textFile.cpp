/*
�����ߣ�Wang
���ܣ�����һ������ļ�������д�����ݣ�Ȼ��ر��ļ����ٰ�����ģʽ����������ȡ��Ϣ��
�汾��V1.0.0
ʱ�䣺13:42 2022/7/18
*/
#include <iostream>
#include <fstream>
using namespace std;
//����һ������ļ�������д�����ݣ�Ȼ��ر��ļ����ٰ�����ģʽ����������ȡ��Ϣ��

void textFileTest() 
{
	ofstream fout("f2.dat", ios::out);//��������ļ�������fout��������ļ�f2.dat

	if (!fout)
	{
		cout << "Cannot open output file.\n";
		exit(1);
	}
	fout << 100 << ' ' << hex << 100 << endl;//��һ��ʮ����������ʮ����������д�������ļ�f2.dat��
	cout << "��100��ʮ���ƺ�ʮ������д�������ļ�f2.dat��......." << endl;
	cout<<"���ַ���\"Hello!\"д�������......"<<endl;
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