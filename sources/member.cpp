/*
 * 成员变量与成员函数
 *	const 对象只能调用const成员函数
 *	只有不修改成员变量的成员函数才能成为const成员函数
 *
 *	C++规定：const成员函数与非const成员函数构成重载关系, 不考虑参数列表是否相同
 *		使用时，const对象使用const成员函数
 *				非const对象使用非const成员函数
 */
#include <iostream>

using namespace std;

class A{
	//private:
	public:
		int i;
	public:
		A(int i1 = 10){
			i = i1;
			cout<<"this : "<<this<<endl;
		}
		void set(int i1){
			i = i1;
			cout<<"i : "<<i<<endl;
		}
		void print()const	//在函数头后加 const关键字 函数称为常函数
		{					//保证不修改成员变量的值的函数才能成为常函数
			cout<<"const print"<<endl;
			cout<<"i : "<<i<<endl;
		}
};

int main(int argc, char *argv[])
{
	const A s1(20);			//常对象在创建时已经通过构造函数进行初始化
	const int x = 0;	//常量必须初始化且不能修改
						//常量、常对象不能做左值
	A s2(100);

	cout<<"s1.i : "<<s1.i<<endl;
	s1.print();			//常对象中只能调用常函数，不能调用其他函数

	s2.print();
	

	return 0;
}
