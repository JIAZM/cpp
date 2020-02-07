#include <iostream>
/*
 * 函数重载构成条件
 * 1. 函数名相同
 * 2. 在同一作用域
 * 3. 参数列表不同
 *		(1) 参数类型不同
 *		(2) 参数个数不同
 * 4. 重载中不考虑返回值是否相同
 *
 * 实现原理：
 * C编译器靠函数名区分函数
 * C++编译器靠函数名+参数列表区分函数
 */

using namespace	std;

int add(int x, int y)
{
	int z = 0;
	z = x + y;
	cout<<"int add():"<<endl;
	return z;
}
								//这两个add函数就已经构成重载
double add(double x, double y)
{
	double z = 0;
	z = x + y;
	cout<<"double add():"<<endl;
	return z;
}

double add(double x, int y)
{
	double z = 0;
	z = x + y;
	cout<<"double - int add():"<<endl;
	return z;
}

class A{
	public:
		double add(double x, int y, double z)	//类中定义的函数作为成员函数只在类中生效
		{										//与全局函数不同，全局函数作用域在全局区
			double m = 0;
			m = x + y;
			cout<<"double - int - double add():"<<endl;
			return m;
		}
		
};

int main(int argc, char *argv[])
{
	double n;
	int m ;

	m = add(1, 2);
	cout<<"m = "<<m<<endl;
	
	n = add(1.22, 2.33);
	cout<<"n = "<<n<<endl;

	n = add(1.22, 2);
	cout<<"n = "<<n<<endl;
	exit(0);
}
