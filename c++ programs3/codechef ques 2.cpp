#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
			cin>>arr[i][j];
		}
	}		
	int res[n][n];
	int x=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		res[i][j]=x;
		x++;	
		}
	}
	int cnt=0;
	int i=n-1;
	while(i>0)
	{
		if(arr[0][i]!= res[0][i])
		{
			for(int j=0;j<i;j++)
			{
				for(int k=j;j<i;j++)
				{
					swap(arr[j][k],arr[k][j]);
				}
				
			}
			cnt++;
		}
		i--;
	}
	cout<<cnt<<endl;
	}
}
