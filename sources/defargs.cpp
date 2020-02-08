/*
 * 函数参数默认值问题
 *
 *
 */

#include <iostream>

using namespace std;

void print(int a = 0, int b = 0, int c = 0)	//C++函数参数可以设置默认值，设置默认值的函数调用时可以不带参数或只带部分参数
						//函数参数一部分有默认值时，要把没有默认值的参数放到参数列表的右边
{						//使用带默认值的有参构造函数(默认构造函数)代替无参默认构造函数 初始化对象内容
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	cout<<"c = "<<c<<endl;
}


int main(int argc, char *argv[])
{
	print(1, 2, 3);
	print();
	print(10);
	print(10, 20);
	
	exit(0);
}
