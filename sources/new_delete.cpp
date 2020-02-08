//动态创建和释放对象
//new	&	delete
//在堆区创建内存

#include <iostream>

using namespace std;

class A{
	private:
		int id;
		string name;
	public:
		A(int id1 = 0, string name1 = ""){
			id = id1;
			name = name1;
			cout<<"Constructor called"<<endl;
			cout<<"this point on : "<<this<<endl;
		}

		void view()
		{
			cout<<"id = "<<id<<endl;
			cout<<"name = "<<name<<endl;
		}

		~A(){
			cout<<"Destrctor called"<<endl;
			cout<<"this point on : "<<this<<endl;
		}
};

int main(int argc, char * argv[])
{
	cout<<"s1:"<<endl;
	A s1;
	cout<<"\n"<<endl;

	cout<<"s2:"<<endl;
	A s2;
	cout<<"\n"<<endl;

	A *s3 = new A;
	//在堆区生成一块内存, 不需要测生成内存大小
	/*
	 * 1.根据数据类型大小开辟一块内存空间
	 * 2.调用类的构造函数完成内存初始化
	 * 3.返回这块内存的首地址
	 */
	s3->view();
	cout<<"\n"<<endl;

	A *s4 = new A(1, "abc");
	s4->view();
	cout<<"\n"<<endl; 

	cout<<"s5:"<<endl;
	A *s5 = new A[3];	//以类的格式生成对象数组
						//使用new生成对象数组时只能调用默认构造函数, 且不能传参
	cout<<"\n"<<endl; 


	delete s3;
	delete s4;
	delete[] s5;		//注意删除对象数组的写法 delete[] <object>
	
	return 0;
}
