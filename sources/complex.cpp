/*
 * 复合：把一个类的对象作为另一个类的成员 - 一种嵌套结构
 * 复合 - 也是以栈的方式创建对象B{A}
 * 		先创建类中的复合类的对象A
 *		再创建类B的对象
 */

#include <iostream>

using namespace std;

class A{
	private:
		int x;
		int y;
	public:
		A(int x1 = 0, int y1 = 1){
			x = x1;
			y = y1;
			cout<<"A Constructor function called"<<endl;
			cout<<"this : "<<this<<endl;
			cout<<"x : "<<x<<endl;
			cout<<"y : "<<y<<endl;
		}
		~A(){
			cout<<"A Destructor function called"<<endl;
			cout<<"this : "<<this<<endl;
		}
};

class B{
	private:
		int z;
		A a;
	public:
		B(int z1 = 2){
			z = z1;
			cout<<"B Constructor function called"<<endl;
			cout<<"this : "<<this<<endl;
			cout<<"z : "<<z<<endl;
		}
		~B(){
			cout<<"B Destructor function called"<<endl;
			cout<<"this : "<<this<<endl;
		}
};

int main(int argc, char *argv[])
{
	B b;

	return 0;
}
