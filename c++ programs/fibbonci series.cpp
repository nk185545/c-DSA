#include<iostream>
using namespace std;
int main()
{
	int a=0,b=1;
	int n;
	cout<<"enter the value of n: "<<endl;
	cin>>n;
	cout<<"fibbonci series upto "<<n<<" is ";
	cout<<a<<" ";
	for(int i=0;i<n;i++)
	{
		int c=a+b;
		cout<<c<<" ";
		a=b;
			b=c;
	
	}
	return 0;
}
