#include <fstream>
#include <windows.h>
#include <string>  //与opencv的命名空间CV有冲突，不能在一个文件中使用
using namespace std;
int main()
{
    string path = "E://1";//测试路径
    remove("E://1/1.txt");//删除文件
  //  rename("H://test/b.txt", "H://test/c.txt");//将b.txt重命名为c.txt

    return 0;
}