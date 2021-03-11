#include<iostream>
using namespace std;
int palindromePartition(string str)
{
	int n=str.length();
	int count[n][n];
	bool palindrome[n][n];
	for(int i=0;i<n;i++)
	{
		count[i][i]=0;
		palindrome[i][i]=true;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			if(l==2 && str[i]==str[j])
			{
				palindrome[i][j]=true;
			}
			else
			{
				if((str[i]==str[j] && palindrome[i+1][j-1]))
				palindrome[i][j]=true;
				else
				palindrome[i][j]=false; 
			}
			if(palindrome[i][j]==true)
			{
				count[i][j]=0;
			}
			else
			{
				count[i][j]=INT_MAX;
				for(int k=i;k<=j-1;k++)
				{
					count[i][j]=min(count[i][j],count[i][k]+count[k+1][j]+1);
				}
			}
		}
	}
	return count[0][n-1];
}
int main()
{
	cout<<"enter string :";
	string str;
	cin>>str;
	int ans=palindromePartition(str);
	cout<<ans;
}
