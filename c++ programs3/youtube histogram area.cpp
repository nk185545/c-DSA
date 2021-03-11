#include<iostream>
using namespace std;
int maxArea(int arr[],int n)
{
	int left=0,right=0;
	int length,maxarea=0;
	for(int i=1;i<n;i++)
	{
		int k=i-1;
		int j=i+1;
		while(arr[k]>arr[i]&&k>=0)
		{
			 left=k;
			 k--;
		}
		while(arr[j]>arr[i] && j<n)
		{
			right=j;
			j++;
		}
		length=right-left-1;
		int area=length*arr[i];
		maxarea=max(area,maxarea);
	}
	return maxarea;
}
int main()
{
	int n;
	cout<<"enter number of heights: ";
	cin>>n;
	int arr[n];
	cout<<"enter heights: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int ans=maxArea(arr,n);
	cout<<ans;
}
