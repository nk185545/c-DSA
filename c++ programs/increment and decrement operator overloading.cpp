#include<iostream>
using namespace std;
class increment
{public:
	int x;
	public:
		void getdata(int a)
		{
			x=a;
		}
		void showdata()
		{
			cout<<x;
		}
		increment operator++()
		{
			increment i;
			i.x=++x;
			return (i);
		}
			increment operator--()
		{
			increment i;
			i.x=--x;
			return (i);
		}
	
};
int main()
{
	increment i1,i2,i3;
	i1.getdata(43);
	cout<<"value entered: ";
    i1.showdata();
	i2=++i1;
	i3=--i1;
	cout<<endl;
	cout<<"value after increment: ";
   i2.showdata();
   cout<<endl;
   cout<<"value after decrement: ";
 i3.showdata();
	return 0;
}
