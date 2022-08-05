#include <iostream>

// ��Ϊ��Ҫwindows��API����
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
    // main ���������߳�
    //�����߳�
    HANDLE hThread1;
    HANDLE hThread2, hThread3;
    hThread2 = CreateThread(NULL, 0, Fun2Pro, NULL, 0, NULL);
    hThread3 = CreateThread(NULL, 0, Fun3Pro, NULL, 0, NULL);
    // �رվ��   �رվ������û�йرմ������߳�
    // ֻ�ǹر������߳��д��̵߳ľ�����Ǹ��̵߳��ں����ü�����1

    CloseHandle(hThread2);
    CloseHandle(hThread3);

    hMutex = CreateMutex(NULL, false, NULL);  // ����һ�������Ļ������

    // Ϊ��ֹ���̻߳�δ���������߳̾��˳�������� sleep() �����߳���ͣһС��ʱ��
    Sleep(4000);  // ��ͣ��ǰ�߳� ��λ����

}

// ģ�� �����߳���ͬʱ��Ʊ
DWORD WINAPI Fun2Pro(
    LPVOID lpParameter
)
{
    while (true)
    {
        WaitForSingleObject(hMutex, INFINITE);  // ���뻥�����
        if (ticket > 0)
        {
            std::cout << "�߳�1������Ʊ����ƱΪ��" << ticket-- << "\n";
        }
        else
            break;

        //�ͷŻ�����������Ȩ
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
        WaitForSingleObject(hMutex, INFINITE);  // ���뻥�����
        if (ticket > 0)
        {
            std::cout << "�߳�2������Ʊ����ƱΪ��" << ticket-- << "\n";
        }
        else
            break;
        ReleaseMutex(hMutex);

    }
   
    return 0;

}