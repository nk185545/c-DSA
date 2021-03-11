#include<iostream>
using namespace std;
int coinchange(int arr[],int n,int sum)
{
	int dp[n][sum+1];
	for(int i=0;i<n;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<=sum;i++)
	{
		if((i%arr[0])==0)
		{
			dp[0][i]=1;
		}
		else
		{
			dp[0][i]=0;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-arr[i]];
			}
		}
	}
	return dp[n-1][sum];
}
int main()
{
	int s,sum;
	cout<<"enter total sum : ";
	cin>>sum;
	cout<<"enter total number of coins:  ";
	cin>>s;
	int arr[s];
	cout<<"enter coins: ";
	for(int i=0;i<s;i++)
	{
		cin>>arr[i];
	}
	int x=coinchange(arr,s,sum);
	cout<<x;
	return 0;
}
