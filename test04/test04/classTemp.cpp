/*
开发者：Wang
功能：在类模板外定义成员函数
版本：V1.0.0
时间：16:20 2022/7/18
*/
#include <iostream>
using namespace std;

template <typename T>
class Three
{
public:
	Three(T a, T b, T c);
	T sum();
private:
	T x, y, z;
};
template <typename T>
Three <T> ::Three(T a, T b, T c)
{
	x = a; y = b; z = c;
}
template <typename T>
T Three<T>::sum()
{
	return x + y + z;
}

void classTempTest()
{
	int x1, x2, x3;
	cout << "请输入三个整数：";
	cin >> x1 >> x2 >> x3;
	Three<int> sum1(x1, x2, x3);
	cout << "三个整数之和是：" << sum1.sum() << endl;
	double d1, d2, d3;
	cout << "请输入三个双精度数：";
	cin >> d1 >> d2 >> d3;
	Three<double> sum2(d1, d2, d3);
	cout << "三个双精度数之和是：" << sum2.sum() << endl;
}
