/*
开发者：Wang
功能：在类模板体外定义成员函数
版本：V1.0.0
时间：10:26 2022/7/14
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
Three<T>::Three(T a, T b, T c)
{
	x = a;
	y = b;
	z = c;
}
template <typename T>
T Three<T>::sum()
{
	return x + y + z;
}

int main()
{
	Three<int> sum1(3, 5, 7);
	Three<double> sum2(12.34, 34.56, 56.78);
	cout << "三个整数的和为：" << sum1.sum() << endl;
	cout << "三个双精度数的和为：" << sum2.sum() << endl;
	return 0;
}