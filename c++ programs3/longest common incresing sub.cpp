#include<iostream>
using namespace std;
int LIS(int arr[],int n)
{
	int cnt=0;
	int x=0;
	for(int i=0;i<n-1;i++)
	{
		if(x<=arr[i])
		{
		cnt++;	
		 x=arr[i+1];
		}
		
	}
	return cnt;
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
	int res=LIS(arr,n);
	cout<<res;
	return 0;
}
