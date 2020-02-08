/*
 * 析构函数
 * 释放对象运行时占有的资源
 * 析构函数名与类名相同且带有~符号
 * 没有参数和返回值，不能重载
 *
 * 对象的构造和析构次序: 通过this指针查看
 * 	实验证明对象的构造与析构次序按照入栈出栈次序
 */

#include <iostream>

using namespace std;

class A{
	private:
		int id;
		string name;
	public:
		A(int id1 = 0, string name1 = "")
		{
			cout<<"Constructor called"<<endl;
		}
		~A()
		{
			cout<<"Destruct function"<<endl;
			cout<<"this point point on : "<<this<<endl;
		}
};

int main(int argc, char *argv[])
{
	A s1;
	cout<<"s1 address"<<&s1<<endl;
	A s2;
	cout<<"s2 address"<<&s2<<endl;
	
	//exit(0);
	return 0;
}
