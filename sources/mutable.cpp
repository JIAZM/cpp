/*
 * mutable(易变型)成员变量
 *
 */

#include <iostream>

using namespace std;

class A{
	private:
		int x;
		int y;
	public:
		mutable int z;	//定义为易变型成员变量

		A(int x1 = 0, int y1 = 1, int z1 = 2){
			x = x1;
			y = y1;
			z = z1;
			cout<<"Constructor function called"<<this<<endl;
		}
		void set_z(int z1)const{	//只修改易变型成员变量的成员函数可以成为const成员函数
			z = z1;
		}
		void print()const{
			cout<<"x : "<<x<<endl;
			cout<<"y : "<<y<<endl;
			cout<<"z : "<<z<<endl;
		}
};
int main(int argc, char *argv[])
{
	const A s1(1, 10,100);
	s1.print();

	s1.z = 200;
	s1.print();

	s1.set_z(300);
	s1.print();

	return 0;
}
