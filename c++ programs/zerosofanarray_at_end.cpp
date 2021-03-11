#include<iostream>
using namespace std;
void zero_at_end(int arr[],int n)
{
	int i=0;
	int j=n-1;
	while(i<j)
	{
		if(arr[i]!=0)
		{
			i++;
		}
		if(arr[i]==0)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			j--;
		}
	}
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
		for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	zero_at_end(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
