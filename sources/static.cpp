/*
 *	静态成员变量问题	static
 *		静态成员变量不依赖于对象存在，生命周期很长
 *		静态成员变量存储在静态(全局)区
 *		可以用类名直接访问
 *		所有对象共享一套静态成员变量
 *
 *	静态成员函数问题	static void xxx(void);
 *		静态成员函数只能操作静态成员变量
 *		静态成员函数可以在没有对象的情况下通过类名直接调用静态成员函数对静态变量进行操作
 *		调用静态成员函数时不会向函数传递this指针，故静态成员函数不知道对象的位置，也不需要创建对象
 *
 */

#include <iostream>

using namespace std;

class A{
	//private:
	public:
		int x;
		mutable int y;
		static int z;	//声明静态成员变量
	public:
		A(int x1 = 0, int y1 = 1){
			x = x1;
			y = y1;
			cout<<"constructor function called"<<endl;
		}
		void set(int x1, int y1){
			x = x1;
			y = y1;
			cout<<"non const set function called"<<endl;
		}
		
		void set_y(int y1)const{
			y = y1;
			cout<<"const set function called"<<endl;
		}
		void print()const{						//非静态成员函数可以操作静态/非静态成员变量
			cout<<"this : "<<this<<endl;
			cout<<"x : "<<x<<endl;
			cout<<"y : "<<y<<endl;
			cout<<"\r"<<endl;
		}
		static void print_z(void){	//静态成员函数
			cout<<"A::z = "<<A::z<<endl;
		}
		static void set_z(int z1){	//静态成员函数只能使用/操作精彩成员变量, 无法操作非静态成员变量
			z = z1;
		}
};
int A::z = 0;

int main(int argc, char *argv[])
{
	A s1;
	s1.print();

	const A s2;
	s2.print();
	s2.set_y(100);
	s2.print();

	cout<<"&s1.z : "<<&s1.z<<endl;	//两个对象中static成员变量内存地址相同	且不与其他成员变量在同一区域
	cout<<"&s2.z : "<<&s2.z<<endl;
	cout<<"&A::z : "<<&A::z<<endl;	//由类定义的所有对象共享同一个z(static成员变量)
									//C++允许使用类名直接访问static成员变量	A::z
	cout<<"\r"<<endl;

	cout<<"s1.z : "<<s1.z<<endl;
	s2.z = 30;
	cout<<"s2.z : "<<s2.z<<endl;
	cout<<"\r"<<endl;

	A::set_z(40);
	A::print_z();
	cout<<"\r"<<endl;

	return 0;
}
