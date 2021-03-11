#include<iostream>
using namespace std;
bool print(int arr[],int n,int sum)
{
	int dp[n+1][sum+1];
	dp[0][0]=1;
	for(int i=1;i<=sum;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j<arr[i-1])
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				
				dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	int i=n,j=sum;
	while(i>=0 && j>=0)
	{
		
		//cout<<i<<"  "<<j<<endl;
		if(j<arr[i-1] && dp[i-1][j]==1)
		{
			cout<<arr[i-1]<<" ";
			i--;
		}
		else
		{
			j=j-arr[i-1];
			i--;
		}
	}
	return dp[n][sum];
}
void sumPartition(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
	 sum=sum+arr[i];
	}
	if(sum%2 !=0)
	{
		cout<<"array cant be patitioned in two subarrays: ";
		return;
	}
	else
	{
		if(print(arr,n,sum/2))
		{
			cout<<"can be partitioned in : ";
		}
	}
}
int main()
{   int n;
    cout<<"enter number of inputs: ";
    cin>>n;
	int arr[n];
	cout<<"enter array elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sumPartition(arr,n);
}
