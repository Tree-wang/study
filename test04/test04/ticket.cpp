#include <iostream>
#include <Windows.h>

using namespace std;

DWORD WINAPI Fun2Pro(
	__in LPVOID lpParameter
);

DWORD WINAPI Fun3Pro(
	__in LPVOID lpParameter
);

int ticket = 100;
HANDLE hMutex;

void ticketTest()
{
	int index = 0;
	HANDLE hThread1;
	HANDLE hThread2, hThread3;
	hThread2 = CreateThread(NULL, 0, Fun2Pro, NULL, 0, NULL);
	hThread3 = CreateThread(NULL, 0, Fun2Pro, NULL, 0, NULL);
	CloseHandle(hThread2);
	CloseHandle(hThread3);

	hMutex = CreateMutex(NULL, false, NULL);
	Sleep(2000);
}

DWORD WINAPI Fun2Pro(
	LPVOID lpParameter
)
{
	while (true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (ticket > 0)
		{
			cout << "线程1正在售票，余票为：" << ticket-- << "\n";
			Sleep(1000);
		}
		else
			break;
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
		WaitForSingleObject(hMutex, INFINITE);
		if (ticket > 0)
		{
			cout << "线程2正在售票，余票为：" << ticket-- << endl;
		}
		else 
			break;
	}
	return 0;
}
