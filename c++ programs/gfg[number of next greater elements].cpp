#include<iostream>
#include<stack>
using namespace std;
void nextgreater(int arr[],int ans[],int n)
{
	stack<int>s;
	s.push(n-1);
	ans[n-1]=-1;
	for(int i=n-2;n>=0;i--)
	{
		if(arr[i]<arr[s.top()])
		{
			ans[i]=s.top();
			s.push(i);
		}
	else
	{
		while(s.size() > 0 && arr[s.top()]< arr[i])
		{
			s.pop();
		}
		if(s.size()==0)
		{
			ans[i]=-1;
			s.push(i);
		}
		else
		{
		ans[i]=s.top();
		s.push(i);
		}	
	}
}
}
void count(int arr[],int dp[],int n)
{
	int ans[n]={0};
	nextgreater(arr,ans,n);
	for(int i=n-1;i>=0;i--)
	{
		if(ans[i]==-1)
		{
			dp[i]=0;
		}
		else
		{
			dp[i]=1+dp[ans[i]];
		}
	}
}
int ansquery(int dp[],int i)
{
	return dp[i];
}
int main()
{
	int n,i;
	cout<<"enter number of elements: ";
	cin>>n;
	int arr[n];
	int ans[n],dp[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter index: ";
	cin>>i;
	count(arr,dp,n);
	 cout<<ansquery(dp,i);
	// for(int i=0;i<n;i++)
	 //{
	 //	cout<<ans[i]<<" ";
	 //}
	 
}
