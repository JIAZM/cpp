/*
 * 构造函数的初始化列表
 * 定义类时，不能在成员变量的声明处初始化成员变量，对成员变量的初始化一般要在构造函数中进行
 * C++允许在构造函数的初始化列表中初始化成员变量
 *
 * 初始化列表只能在构造函数中使用，其他函数没有初始化列表
 *
 */

#include <iostream>

using namespace std;

class A{
	private:
		int id;
		string name;
		const int m;	//在类中声明一个常量 - 【常量必须进行初始化】 
						//c++规定：常量不能在构造函数中初始化
	public:
		A(int id1 = 0, string name1 = ""):m(0)	//常量的初始化方法, 常量只能在初始化列表中初始化，变量在构造函数中初始化也可以
		{									//在构造函数的函数头后加 :<object>(value),...
			id = id1;
			name = name1;
			cout<<"this :"<<this<<endl;
			cout<<"id :"<<id<<endl;
			cout<<"name :"<<name<<endl;
			cout<<"m :"<<m<<endl;
			cout<<"\r"<<endl;
		}
};

int main(int argc, char *argv[])
{
	A s1;

	return 0;
}
