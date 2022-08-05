#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h>
using namespace std;

class CFile
{
public:
	CFile();   // 类的构造函数
	~CFile();   // 类的析构函数
	void tFout();//文本文件写入
	void tFin();//文本文件读出
	void bFout();//二进制文件写入
	void bFin();//二进制文件读出
	void Remove();//删除文件
	void Rename();//重命名文件
};

CFile::CFile()   // 类的构造函数
{
}


CFile::~CFile() {}   // 类的析构函数


//文本文件写入
void  CFile::tFout()
{
	string s, str1;//声明文件名s，要输入的信息str1
	cout << "以文本文件写入" << endl;
	cout << "请输入要写入的文件名:";
	cin >> s;//输入文件名
	ofstream fout(s, ios::out);//定义输出文件流对象fout，打开输出文件s

	if (!fout)//如果文件打开失败
	{
		cout << "Cannot open output file.\n";
		exit(1);
	}
	cout << "要写入的信息：";
	cin >> str1;//输入写入的信息
	fout << str1 << endl;
	fout.close();//文件关闭
}

//文本文件读出
void  CFile::tFin()
{
	string s1, str2;
	cout << "以文本文件读出" << endl;
	cout << "请输入要读出的文件名:";
	cin >> s1;
	ifstream fin(s1, ios::in);
	if (!fin)
	{
		cout << "Cannot open input file.\n";
		exit(1);
	}
	char str[50];//定义字符串数组str,用于存放从文件中取出的字符
	while (fin)
	{
		fin.getline(str, 50);//取出49个字符
		cout << str << endl;
	}
	fin.close();

}
void CFile::bFout()
{
	string s, str1;
	cout << "以二进制文件写入" << endl;
	cout << "请输入要写入的文件名:";
	cin >> s;
	ofstream outf(s, ios::binary);

	if (!outf)
	{
		cout << "Cannot open output file\n,";
		exit(1);
	}
	cout << "要写入的信息：";
	cin >> str1;
	for (int i = 0; i < str1.length(); i++)
	{
		outf.put(str1[i]);
	}
	outf.close();
}

void CFile::bFin()
{
	string s1;
	cout << "以二进制文件读出" << endl;
	cout << "请输入要读出的文件名:";
	cin >> s1;
	ifstream inf(s1, ios::binary);
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
}

void CFile::Remove()
{
	char FileName[256] = { 0 };//初始化文件名
	cout << "请输入要删除的文件：";
	cin >> FileName;
	if (0 == remove(FileName))
	{
		cout << "删除成功" << endl;
	}
	/*cout << "请输入删除的文件名：";
	string path;
	cin >> path;
	remove(path);*/
}

void CFile::Rename()
{
	char source[256];//文件路径
	char newname[256];
	cout << "请输入要重命名的文件路径:" << endl;
	cin >> source;
	cout << "请输入文件的新名称:" << endl;
	cin >> newname;

	if (!_access(source, 0))//如果文件存在:
	{
		if (!rename(source, newname))//删除成功
		{
			cout << source << " 成功重命名为: " << newname << endl;
		}
		else//无法重命名:文件打开或无权限执行重命名
		{
			cout << "文件无法重命名(可能原因如下):" << endl;
			cout << "\t" << "1. " << newname << " 已存在" << endl
				<< "\t" << "2. " << newname << " 正在使用,未关闭." << endl
				<< "\t" << "3. " << "你没有权限重命名此文件." << endl;
		}
	}
	else//文件不存在
	{
		cout << source << " 不存在,无法重命名." << endl;
	}
	cin.get();
}
void fileTest()
{
	CFile file;
	while (1)
	{
		cout << "1.写入文本文件" << endl;
		cout << "2.读出文本文件" << endl;
		cout << "3.写入二进制文件" << endl;
		cout << "4.读出文本文件" << endl;
		cout << "5.删除文件" << endl;
		cout << "6.重命名文件" << endl;
		cout << "0.退出" << endl;

		int a;
		cin >> a;
		switch (a)
		{
		case 1:
			system("cls");
			file.tFout();
			break;
		case 2:
			system("cls");
			file.tFin();
			break;
		case 3:
			system("cls");
			file.bFout();
			break;
		case 4:
			system("cls");
			file.bFin();
			break;
		case 5:
			system("cls");
			file.Remove();
			break;
		case 6:
			system("cls");
			file.Rename();
			break;
		case 0:
			exit(1);
		}

	}
}
