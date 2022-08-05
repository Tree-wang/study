#include <iostream>
using namespace std;

//此程序是为了处理求三角形面积时出现的异常。
//异常包括边不能为负和两边之和大于第三边。处理异常时应先处理边不能为负然后再处理两边之和小于第三边的异常。
double triarea(int a, int b, int c)
{
	double s = (a + b + c) / 2;
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		throw 1;
	}
	
	return sqrt(s * (s - a) * (s - b));
}

int main()
{
	int x;
	int y;
	int z;
	double area;
	
	try 
	{
		cin >> x >> y >> z;
		if (x <= 0 || y <= 0 || z <= 0)
		{
			throw 1.0;
		}
		if (x > 0 && y > 0 && z > 0)
		{
			area = triarea(x, y, z);
		}
		cout << "三角形的面积为： " << area << endl;
	}
	catch(int)
	{
		cout << "两边之和小于第三边，不能构成三角形" << endl;
	}
	catch (double)
	{
		cout << "边不能为负" << endl;
	}
	return 0;
}