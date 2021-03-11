#include<iostream>
using namespace std;
int main()
{
	int a[]={1,2,3,4,5,6};
	int n=6;
	int temp[n];
	int j=0;
	int k=2;
	for(int i=k;i<n;i++)
	{
		temp[j]=a[i];
		j++;
	}
	for(int i=0;i<k;i++)
	{
		temp[j]=a[i];
		j++;
	}
	for(int i=0;i<n;i++)
	{
		cout<<temp[i]<<" ";
	}
	return 0;
}
