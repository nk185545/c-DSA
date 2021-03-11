#include<iostream>
using namespace std;
void findUnique(int arr[],int n)
{
	int Xor=arr[0];
	int x=0,y=0;
	for(int i=0;i<n;i++)
	{
		Xor=Xor^arr[i];
	}
	int setBit;
	setBit=Xor & ~(Xor-1);
	for(int i=0;i<n;i++)
	{
		if(setBit & arr[i] )
		{
			x=x^arr[i];
		}
		else
		{
			y=y^arr[i];
		}
	}
	cout<<x<<" "<<y;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	findUnique(arr,n);
}
