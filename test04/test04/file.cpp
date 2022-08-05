#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h>
using namespace std;

class CFile
{
public:
	CFile();   // ��Ĺ��캯��
	~CFile();   // �����������
	void tFout();//�ı��ļ�д��
	void tFin();//�ı��ļ�����
	void bFout();//�������ļ�д��
	void bFin();//�������ļ�����
	void Remove();//ɾ���ļ�
	void Rename();//�������ļ�
};

CFile::CFile()   // ��Ĺ��캯��
{
}


CFile::~CFile() {}   // �����������


//�ı��ļ�д��
void  CFile::tFout()
{
	string s, str1;//�����ļ���s��Ҫ�������Ϣstr1
	cout << "���ı��ļ�д��" << endl;
	cout << "������Ҫд����ļ���:";
	cin >> s;//�����ļ���
	ofstream fout(s, ios::out);//��������ļ�������fout��������ļ�s

	if (!fout)//����ļ���ʧ��
	{
		cout << "Cannot open output file.\n";
		exit(1);
	}
	cout << "Ҫд�����Ϣ��";
	cin >> str1;//����д�����Ϣ
	fout << str1 << endl;
	fout.close();//�ļ��ر�
}

//�ı��ļ�����
void  CFile::tFin()
{
	string s1, str2;
	cout << "���ı��ļ�����" << endl;
	cout << "������Ҫ�������ļ���:";
	cin >> s1;
	ifstream fin(s1, ios::in);
	if (!fin)
	{
		cout << "Cannot open input file.\n";
		exit(1);
	}
	char str[50];//�����ַ�������str,���ڴ�Ŵ��ļ���ȡ�����ַ�
	while (fin)
	{
		fin.getline(str, 50);//ȡ��49���ַ�
		cout << str << endl;
	}
	fin.close();

}
void CFile::bFout()
{
	string s, str1;
	cout << "�Զ������ļ�д��" << endl;
	cout << "������Ҫд����ļ���:";
	cin >> s;
	ofstream outf(s, ios::binary);

	if (!outf)
	{
		cout << "Cannot open output file\n,";
		exit(1);
	}
	cout << "Ҫд�����Ϣ��";
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
	cout << "�Զ������ļ�����" << endl;
	cout << "������Ҫ�������ļ���:";
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
	char FileName[256] = { 0 };//��ʼ���ļ���
	cout << "������Ҫɾ�����ļ���";
	cin >> FileName;
	if (0 == remove(FileName))
	{
		cout << "ɾ���ɹ�" << endl;
	}
	/*cout << "������ɾ�����ļ�����";
	string path;
	cin >> path;
	remove(path);*/
}

void CFile::Rename()
{
	char source[256];//�ļ�·��
	char newname[256];
	cout << "������Ҫ���������ļ�·��:" << endl;
	cin >> source;
	cout << "�������ļ���������:" << endl;
	cin >> newname;

	if (!_access(source, 0))//����ļ�����:
	{
		if (!rename(source, newname))//ɾ���ɹ�
		{
			cout << source << " �ɹ�������Ϊ: " << newname << endl;
		}
		else//�޷�������:�ļ��򿪻���Ȩ��ִ��������
		{
			cout << "�ļ��޷�������(����ԭ������):" << endl;
			cout << "\t" << "1. " << newname << " �Ѵ���" << endl
				<< "\t" << "2. " << newname << " ����ʹ��,δ�ر�." << endl
				<< "\t" << "3. " << "��û��Ȩ�����������ļ�." << endl;
		}
	}
	else//�ļ�������
	{
		cout << source << " ������,�޷�������." << endl;
	}
	cin.get();
}
void fileTest()
{
	CFile file;
	while (1)
	{
		cout << "1.д���ı��ļ�" << endl;
		cout << "2.�����ı��ļ�" << endl;
		cout << "3.д��������ļ�" << endl;
		cout << "4.�����ı��ļ�" << endl;
		cout << "5.ɾ���ļ�" << endl;
		cout << "6.�������ļ�" << endl;
		cout << "0.�˳�" << endl;

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
