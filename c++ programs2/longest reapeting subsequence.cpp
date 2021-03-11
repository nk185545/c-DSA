#include<iostream>
using namespace std;
int LCS(string s1)
{
	int n=s1.length();
	string s2=s1;
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
	dp[i][0]=0;
	}
	for(int i=0;i<=n;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1] && i!=j)
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][n];
}
int main()
{
	string s1;
    cout<<"enter string ";
	cin>>s1;
	cout<<"longest reapeting subsequence length is: ";
	int ans=LCS(s1);
	cout<<ans;
}
