/*
�����ߣ�Wang
���ܣ�����ģ���ⶨ���Ա����
�汾��V1.0.0
ʱ�䣺16:20 2022/7/18
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
	cout << "����������������";
	cin >> x1 >> x2 >> x3;
	Three<int> sum1(x1, x2, x3);
	cout << "��������֮���ǣ�" << sum1.sum() << endl;
	double d1, d2, d3;
	cout << "����������˫��������";
	cin >> d1 >> d2 >> d3;
	Three<double> sum2(d1, d2, d3);
	cout << "����˫������֮���ǣ�" << sum2.sum() << endl;
}
