#include <iostream>

// 因为需要windows的API函数
#include<Windows.h>

DWORD WINAPI Fun2Pro(
    __in  LPVOID lpParameter
);
DWORD WINAPI Fun3Pro(
    __in  LPVOID lpParameter
);

int ticket = 100;
HANDLE hMutex;

void ticketTest()
{
    int index = 0;
    // main 函数是主线程
    //创建线程
    HANDLE hThread1;
    HANDLE hThread2, hThread3;
    hThread2 = CreateThread(NULL, 0, Fun2Pro, NULL, 0, NULL);
    hThread3 = CreateThread(NULL, 0, Fun3Pro, NULL, 0, NULL);
    // 关闭句柄   关闭句柄，但没有关闭创建的线程
    // 只是关闭了主线程中此线程的句柄，是该线程的内核引用计数减1

    CloseHandle(hThread2);
    CloseHandle(hThread3);

    hMutex = CreateMutex(NULL, false, NULL);  // 创建一个匿名的互斥对象

    // 为防止子线程还未创建，主线程就退出可以添加 sleep() 让主线程暂停一小段时间
    Sleep(4000);  // 暂停当前线程 单位毫秒

}

// 模拟 俩个线程在同时售票
DWORD WINAPI Fun2Pro(
    LPVOID lpParameter
)
{
    while (true)
    {
        WaitForSingleObject(hMutex, INFINITE);  // 申请互斥对像
        if (ticket > 0)
        {
            std::cout << "线程1正在售票，余票为：" << ticket-- << "\n";
        }
        else
            break;

        //释放互斥对象的所有权
        ReleaseMutex(hMutex);
    }
    return 0;
}
DWORD WINAPI Fun3Pro(
    LPVOID lpParameter
)
{
    while (true)
    {
        WaitForSingleObject(hMutex, INFINITE);  // 申请互斥对像
        if (ticket > 0)
        {
            std::cout << "线程2正在售票，余票为：" << ticket-- << "\n";
        }
        else
            break;
        ReleaseMutex(hMutex);

    }
   
    return 0;

}