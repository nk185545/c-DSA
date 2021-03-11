#include<iostream>
using namespace std;
void calculateFrequency(int fre[],int n,int dp[][50])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				dp[i][j]=fre[i-1];
			}
			else if(i<j)
			{
				dp[i][j]=dp[i][j-1]+fre[j-1];
			}
			else
			{
				dp[i][j]=dp[j][i];
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
}
int OBST(int fre[],int n)
{
	int dp[50][50];
	calculateFrequency(fre,n,dp);
	int tree[n+1][n+1];
	for(int i=1;i<=n;i++)
	{
		tree[i][i]=dp[i][i];
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			tree[i][j]=INT_MAX;
			for(int k=i;k<=j;k++)
			{
				int t=tree[i][k-1]+tree[k+1][j]+dp[i][j];
				if(t<tree[i][j])
				{
					tree[i][j]=t;
				}
			}
		}
	}
	return tree[1][n];
}
int main()
{
	int n;
	cout<<"enter number of nodes: ";
	cin>>n;
	int arr[n],fre[n];
	cout<<"enter node number : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>fre[i];
	}
	int ans=OBST(fre,n);
	cout<<ans;
}
