#include<iostream>
using namespace std;
int LIS(int arr[],int n)
{
	int dp[n];
	int ans=0;
	for(int i=0;i<n;i++)
	{
	dp[i]=1;
	}
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<i;j++)
	{
    if(arr[i]>=arr[j])
			{
				dp[i]=max(dp[i],dp[j]+1);
				ans=max(ans,dp[i]);
			}
		}
	}
	return ans;
}
int main()
{
int n;
cout<<"enter number of items: ";
cin>>n;
	int arr[n];
    cout<<"enter input ";
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }
	cout<<"longest increasing subsequence length is: ";
	int ans=LIS(arr,n);
	cout<<ans;
}
