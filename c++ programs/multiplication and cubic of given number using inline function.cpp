#include<iostream>
using namespace std;
class fun{
	float x;
	float y;
	float z;
	public:
	inline	void multiplication()
		{
			cout<<"enter two numbers: ";
			cin>>x>>y;
			cout<<"multiplication of two numbers is: ";
			int mul=x*y;
			cout<<mul<<endl;
		}
	inline	void cubic ()
		{
			cout<<"enter the number: ";
			cin>>z;
			cout<<"cubic of given number is: ";
			float cub=z*z*z;
			cout<<cub;
		}
};
int main()
{
	fun fu;
	fu.multiplication();
	fu.cubic();
	return 0;
}
