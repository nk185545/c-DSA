#include<iostream>
#include<vector>
using namespace std;
int minPath(vector<vector<int > >&v)
{
	int n=v.size()-1;
	int dp[v.size()];
	for(int i=0;i<v[n].size();i++)
	{
		dp[i]=v[n][i];
	}
	for(int i=v.size()-2;i>=0;i--)
	{
		for(int j=0;j<v[i].size();j++)
		{
			dp[i]=min(dp[j],dp[j+1])+v[i][j];
		}
	}
	return dp[0];
}
int main()
{
	vector<vector<int > >v { {2},
	{3,7},
	{8,5,6},
	{6,1,9,3} };
	int sum=minPath(v);
	cout<<sum;
}
