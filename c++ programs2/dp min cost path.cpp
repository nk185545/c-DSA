#include<iostream>
using namespace std;
int min(int a,int b)
{
	if(a>b)
	return b;
	else return a;
}
int minCost(int cost[3][3],int m,int n)
{
	int dp[3][3];
	dp[0][0]=cost[0][0];
	for(int i=1;i<=m;i++)
	{
		dp[i][0]=cost[i][0]+dp[i-1][0];
	}
	for(int i=1;i<=n;i++)
	{
		dp[0][i]=cost[0][i]+dp[0][i-1];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+cost[i][j];
		}
	}
	return dp[m][n];
}
int main()
{
	int cost[3][3]={{1,2,3},{4,8,2},{1,5,3}};
	int m=2,n=1;
	int nas=minCost(cost,m,n);
	cout<<nas;
}
