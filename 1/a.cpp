#include <iostream>

using namespace std;

struct student{	//结构体 - 一种自定义的数据类型
	int id;
	string name;
	int math;
};

class stu{	//类 - 也是一种自定义的数据类型
/*
 *private:	//可以设置访问权限
 *private:	私有成员只有本类内可以访问
 *public:	公有成员本类内, 类外都可以访问
 *protected:	与私有相似，在继承时不同
 */
	public:
		int id;	//类中 变量称为属性	类中定义的变量叫成员变量
		string name;
		int math;
	public:		//通过公有方法操作私有属性(公有成员函数操作私有成员变量)
		void set(int id1, string name1, int math1)	//类中可以有函数 - 通常称为方法
		{											//类中定义的函数叫成员函数		
			id = id1;								//类中成员函数只有一套，每个对象只有成员变量
			name = name1;							//类中定义的函数为inline函数
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
		
/*
 * stu(int id1, string name1, int math1)	构造函数也可以有参数
 * 								# 有参构造函数与无参构造函数可以同时出现在类中- 函数重载技术
 * {				当构造函数有参数时可以通过 stu s4(100, "aaa", -60) 声明新对象
 * 	id = id1;
 * 	name = name1;
 * 	if(math1 < 0){
 * 		cout<<"error math data"<<endl;
 * 		math = 0;
 * 	else	math = math1;
 * 	
 * }
 */
		stu()	//构造函数与类名相同
		{
			id = 0;
			name="";
			math = 0;
			cout<<"no args function called"<<endl;
			//cout<<"id = "<<id<<endl;
			//cout<<"name = "<<name<<endl;
			//cout<<"math = "<<math<<endl;
		}

		void B();	//函数在类内声明，在类外实现
};

void stu::B()		//在类外实现类内声明的函数
{					//函数与类为从属关系 - 也是成员函数，但不是inline函数
					//在类外实现的成员函数加 inline 关键字修饰 - 称为inline函数
					//inline void stu::B()
}

int main(int argc, char *argv[])
{
	struct student s1;
	s1.id = 100;
	s1.name = "zhang san";
	s1.math = 90;
	cout<<"s1.math = "<<s1.math<<endl;
	
	stu s2;	//由类定义对象
	/*
	 * 对象的声明周期
	 * 产生(系统自动调用构造函数) ---> 释放
	 * 类生成对象的时候调用构造函数完成对像内存的初始化
	 */
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
