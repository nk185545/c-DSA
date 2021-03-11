#include<iostream>
using namespace std;
#define mod 1000000007
int countBT(int h)
{
	int count[h+1];
		count[0]=1;
		count[1]=1;
	for(int i=2;i<=h;i++)
	{
		count[i]=(count[i-1]*(2*(count[i-2]%mod)+(count[i-1]%mod)))%mod;
	}
	return count[h];
}
int main()
{
	int h;
	cout<<"enter height :  ";
	cin>>h;
	int ans=countBT(h);
	cout<<ans;
}
