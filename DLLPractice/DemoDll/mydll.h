#pragma once

#ifdef BUILD_MYDLL
#define API_SYMBOL _declspec(dllexport)
#else
#define API_SYMBOL _declspec(dllimport)
#endif // BUILD_MYDLL

extern "C" API_SYMBOL int convert_array(int* data, int len);
