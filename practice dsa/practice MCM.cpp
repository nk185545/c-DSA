#include<iostream>
using namespace std;
int MCM(int arr[],int n)
{
	int dp[n][n];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				dp[i][j]=0;
			}
		}
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++)
			{
				int temp=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
				if(temp<dp[i][j])
				{
					dp[i][j]=temp;
				}
			}
		}
	}
	return dp[1][n];
}
int main()
{
	int n;
	cout<<"enter n(for n matrix there will be n+1 arguments: ";
	cin>>n;
	int arr[n+1];
	cout<<"enter n+1 elements:  ";
	for(int i=0;i<=n;i++)
	{
		cin>>arr[i];
	}
   int ans=	MCM(arr,n);
   cout<<ans;
}
