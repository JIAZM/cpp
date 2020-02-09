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
		void print(){
			cout<<"x : "<<x<<endl;
			cout<<"y : "<<y<<endl;
		}
};

class B{
	private:
		int z;
		A a;
	public:
		B(int z1 = 2):a(200, 300){	//在B的初始化列表中可以指定调用A的构造函数进行初始化
		//B(int x1, int y1, z1):a(x1, y1)	另一种写法，使用初始化列表对复合结构进行初始化
		//创建对象时使用 B b(100, 200, 300)	即可
			z = z1;
			cout<<"B Constructor function called"<<endl;
			cout<<"this : "<<this<<endl;
			cout<<"z : "<<z<<endl;
		}
		~B(){
			cout<<"B Destructor function called"<<endl;
			cout<<"this : "<<this<<endl;
		}
		void print_b(){
			cout<<"print_b()"<<endl;
			cout<<"z : "<<z<<endl;
		}
		void print_a(){
			cout<<"print_a()"<<endl;
			a.print();
		}
};

int main(int argc, char *argv[])
{
	B b;

	b.print_b();
	b.print_a();

	return 0;
}
