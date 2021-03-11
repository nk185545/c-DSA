#include<iostream>
using namespace std;
int LCS(string s1,string s2)
{
	int n1=s1.length();
	int n2=s2.length();
	int dp[n1+1][n2+1];
	for(int i=0;i<=n1;i++)
	{
	dp[i][0]=0;
	}
	for(int i=0;i<=n2;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n1][n2];
}
int main()
{
	string s1,s2;
	cout<<"enter string 1 and string 2  ";
	cin>>s1>>s2;
	cout<<"longest common subsequence length is: ";
	int ans=LCS(s1,s2);
	cout<<ans;
}
