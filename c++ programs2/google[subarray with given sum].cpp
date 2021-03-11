#include<iostream>
using namespace std;
void subarrayWithGivenSum(int arr[],int n,int sum)
{
	int curr_sum=0,j=0;
	curr_sum=arr[0];
	for(int i=1;i<n;i++)
	{
		while(curr_sum > sum && j<i-1)
		{
			curr_sum=curr_sum-arr[j];
			j++;
		}
		if(curr_sum==sum)
		{
			cout<<"sum is found between indices : "<<j<<" to "<<i-1;
			return;
		}
		else
		{
			curr_sum=curr_sum+arr[i];
		}
	}
	cout<<"no subarray found ";
}
int main()
{
	int n;
	cout<<"enter number of elements :";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int sum;
	cout<<"enter the sum ";
	cin>>sum;
	subarrayWithGivenSum(arr,n,sum);
}
