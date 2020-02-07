#include <iostream>

using namespace std;

struct student{	//结构体 - 一种自定义的数据类型
	int id;
	string name;
	int math;
};

class stu{	//类 - 也是一种自定义的数据类型
	//private:	//可以设置访问权限
	public:
		int id;	//类中 变量称为属性	类中定义的变量叫成员变量
		string name;
		int math;
	public:
		void set(int id1, string name1, int math1)	//类中可以有函数 - 通常称为方法
		{											//类中定义的函数叫成员函数		
			id = id1;								//类中成员函数只有一套，每个对象只有成员变量
			name = name1;
			if(math1 >= 0)	math = math1;
			else{
				math = 0;
				cout<<"math数据违规"<<endl;
			}
		}

		void print(){
			cout<<"this"<<this<<endl;	//打印this指针
			cout<<"id = "<<id<<endl;	//C++的标准输出
			cout<<"name = "<<name<<endl;
			cout<<"math = "<<math<<endl;
		}
	
};

int main(int argc, char *argv[])
{
	struct student s1;
	s1.id = 100;
	s1.name = "zhang san";
	s1.math = 90;
	cout<<"s1.math = "<<s1.math<<endl;
	
	stu s2;	//由类定义对象

	//s2.math = 90;	//private 私有权限：私有成员只能在本类中使用
	//cout<<"s2.math = "<<s1.math<<endl;
	
	//使用类中公有成员访问私有成员
	s2.set(100, "li si", 90);	//public 公有权限：公有成员在全局都可以使用
	s2.print();

	cout<<"&S2 = "<<&s2<<endl;	//对象首地址为对象的this指针，调用成员函数时会传入this指针
								//通过this指针找到对象首地址，从而对指定对象进行操作
	cout<<"&S2.id = "<<&s2.id<<endl;
	cout<<"&S2.name = "<<&s2.name<<endl;
	cout<<"&S2.math = "<<&s2.math<<endl;

	cout<<"sizeof(int) = "<<sizeof(int)<<endl;
	cout<<"sizeof(string) = "<<sizeof(string)<<endl;
	cout<<"sizeof(s2) = "<<sizeof(s2)<<endl;

	exit(0);
}
