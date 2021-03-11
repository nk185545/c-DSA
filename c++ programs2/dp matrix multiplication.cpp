#include<iostream>
using namespace std;

void print(int dp[50][50],int i,int j, char& name)
{
	
	if(i==j)
	{
		cout<<name;
		name++ ;
		return ;
	}
	cout<<"(" ;
	int k =dp[j][i] ;
	print(dp,i,k,name) ;
	print(dp,k+1,j,name) ;
	cout<<")";
	
}

int matrixMultiplication(int arr[],int n)
{
	int dp[50][50];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			dp[i][j]=0;
		}
	}
	int min=INT_MAX;
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			   int j=l+i-1;
				dp[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++)
			{
				int t=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
				if(t<dp[i][j])
				{
				dp[i][j]=t;	
				dp[j][i]=k;
				}
			}
		}
		
	}
	char name= 'A' ;
	print(dp,1,n,name) ;
   return dp[1][n];
   }
int main()
{
	int n1;
	cout<<"enter number of Matrices: ";
	cin>>n1;
	int arr[n1+1];
	for(int i=0;i<=n1;i++)
	{
		cin>>arr[i];
	}
   int ans=	matrixMultiplication(arr,n1);
   cout<<ans;
}
