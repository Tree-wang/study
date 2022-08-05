// xsInvokedll.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>

//第一步，创建一个别名，它引用的函数类型需要和dll中的导出函数一致。
typedef int (*LPDO_ARRAY)(int* pArr, int nlen);
int main()
{
    HINSTANCE hDll;//定义一个实例句柄，引用动态库；
    LPDO_ARRAY lpDo_array;//定义一个函数指针，用来指向导出函数

    //第二步，加载DemoDll.dll动态库文件
    hDll = LoadLibrary(L"DemoDll.dll");
    if (hDll != NULL)
    {
        //第三步，获取dll中函数的地址
        lpDo_array = (LPDO_ARRAY)GetProcAddress(hDll, "convert_array");
        if (lpDo_array != NULL)
        {
            //第四步，调用函数
            int nArr[] = { 1,2,4,6 };
            int nlen = sizeof(nArr) / sizeof(int);
            int nRet;

            //通过函数指针lpDo_array调用函数
            nRet = lpDo_array(nArr, nlen);
            std::cout << "返回值：" << nRet << std::endl;
            std::cout << "数组新值： ";
            for (int i = 0; i < nlen; ++i)
            {
                std::cout << nArr[i] << ",";
            }
        }
        //第五步，释放动态库句柄
        FreeLibrary(hDll);
    }

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
