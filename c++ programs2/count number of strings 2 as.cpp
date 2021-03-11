#include<bits/stdc++.h>
using namespace std;
int countOfStrings(int dp[][2][3],int n,int b_count,int c_count)
{
	if(b_count <0 || c_count <0)
	return 0;
	if(n==0)
	return 1;
	if(b_count==0 && c_count==0)
	return 1;
	if(dp[n][b_count][c_count]!=-1)
	 return dp[n][b_count][c_count];
	int res=countOfStrings(dp,n-1,b_count,c_count);
	res+=countOfStrings(dp,n-1,b_count-1,c_count);
	res+=countOfStrings(dp,n-1,b_count,c_count-1);
	return res;
}
int main()
{
	int n;
	cout<<"enter length of strings: ";
	cin>>n;
	int dp[n+1][2][3];
	memset(dp,-1,sizeof(dp));
	int ans=countOfStrings(dp,n,1,2);
	
	cout<<ans;
}
