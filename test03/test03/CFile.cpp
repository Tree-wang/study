#define _CRT_SECURE_NO_WARNINGS
/*
	



*/


#include <stdio.h>
#include <string.h>
#include <stdarg.h>



namespace develop_tools {

	// 文件操作类声明
	class CFile
	{
	private:
		FILE* m_fp;        // 文件指针
		bool  m_bEnBuffer; // 是否启用缓冲区，true-启用；false-不启用

	public:
		CFile();   // 类的构造函数


		~CFile();   // 类的析构函数


		 /*
		 函数名称：open
		 参数：filebname输入文件名称，openmode打开标识
		 返回：ture成功，false失败
		 功能：打开一个文件
		 */
		bool Open(const char* filename, const char* openmode);

		/*
		 函数名称：open
		 参数：filebname输入文件名称，openmode打开标识
		 返回：ture成功，false失败
		 功能：打开一个文件
		 */
		void Fprintf(const char* fmt, ...);

		/*
		 函数名称：open
		 参数：filebname输入文件名称，openmode打开标识
		 返回：ture成功，false失败
		 功能：打开一个文件
		 */
		bool Fgets(char* strBuffer, const int ReadSize);

		/*
		 函数名称：open
		 参数：filebname输入文件名称，openmode打开标识
		 返回：ture成功，false失败
		 功能：打开一个文件
		 */
		void Close();
	};



	class CFile_Log : public CFile
	{
	public:
		~CFile_Log() {}

		//getinstance
		static CFile_Log* GetInstance()
		{
			if (m_pInstance == nullptr)
				m_pInstance = new CFile_Log();
			return m_pInstance;
		}

		//写入时，文件大于20M，切换下一个文件1,2,3,1,2,3
		void SetFormat(int nMaxrollnums, int nMaxFilesize = 20 * 1024 * 1024);

		//logout函数,带时间标签  2022-07-21 09：11:11 程序启动
		void LogOut(const char* fmt, ...);
		//单例模式
	private:
		CFile_Log();
		static CFile_Log* m_pInstance;


	};

	CFile_Log* CFile_Log::m_pInstance = nullptr;





}

int main()
{
	develop_tools::CFile_Log::GetInstance()->LogOut("Cfile_Log init");


	//其他操作



}


CFile::CFile()   // 类的构造函数
{
	m_fp = 0;
	m_bEnBuffer = true;
}


// 关闭文件指针
void CFile::Close()
{
	if (m_fp != 0) fclose(m_fp);  // 关闭文件指针
	m_fp = 0;
}

CFile::~CFile()   // 类的析构函数
{
	Close();  // 调用Close释放资源
}



// 打开文件，参数与fopen相同，打开成功true，失败返回false         
bool CFile::Open(const char* filename, const char* openmode)
{
	Close();  // 打开新的文件之前，如果已经打开了文件，关闭它。

	if ((m_fp = fopen(filename, openmode)) == 0) return false;

	return true;
}

// 调用fprintf向文件写入数据
void CFile::Fprintf(const char* fmt, ...)
{
	if (m_fp == 0) return;

	va_list arg;
	va_start(arg, fmt);
	vfprintf(m_fp, fmt, arg);
	va_end(arg);

	if (m_bEnBuffer == false) fflush(m_fp);
}

// 调用fgets从文件中读取一行
bool CFile::Fgets(char* strBuffer, const int ReadSize)
{
	if (m_fp == 0) return false;

	memset(strBuffer, 0, ReadSize);

	if (fgets(strBuffer, ReadSize, m_fp) == 0) return false;

	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2) { printf("请输入待打开的文件名。\n"); return -1; }

	CFile File;

	if (File.Open(argv[1], "r") == false) { printf("File.Open(%s)失败。\n", argv[1]); return -1; }

	char strLine[301];

	while (true)
	{ // 从文件中读取每一行
		if (File.Fgets(strLine, 300) == false) break;

		printf("%s", strLine);   // 把从文件中读到的内容显示到屏幕
	}
}
