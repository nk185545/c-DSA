#include<iostream>
using namespace std;
struct minmax
{
	int a;
	int b;
}mm;
minmax DAC(int arr[],int l,int h)
{
	if(l==h)
	{
		mm.a=arr[l];
		mm.b=arr[l];
		return mm;
	}
	int mid=(l+h)/2;
  minmax a1=DAC(arr,l,mid);
  minmax a2=DAC(arr,mid+1,h);
  minmax a3;
	a3.a=min(a1.a,a2.a);
	a3.b=max(a1.b,a2.b);
	return a3;
}
int main()
{
	int n;
	cin>>n;
	minmax bt;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
bt=	DAC(arr,0,n-1);
	cout<<"min is : "<<bt.a<<"   max is  :"<<bt.b;
	return 0;
}

