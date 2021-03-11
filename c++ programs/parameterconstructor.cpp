#include<iostream>
using namespace std;
class parameter
{
	public:
		int id;
		float salary;
		string name;
		public:
			parameter(int i,float s,string n)
			{
				id=i;
				salary=s;
				name=n;
			}
			void show()
			{
				cout<<" employee name is "<<name<<"salary is:"<<salary<<"id is:"<<id<<endl;
			}
};
int main()
{
	parameter p1=parameter(185545,10000,"neetu");
	parameter p2=parameter(185543,20000,"shubham");
	p1.show();
	p2.show();
	return 0;
	
}
