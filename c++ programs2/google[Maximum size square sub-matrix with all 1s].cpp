#include<iostream>
#include<vector>
using namespace std;
void subSquareMatrix(vector<vector<int> >matrix)
{
	int rows=matrix.size();
	int columns=matrix[0].size();
	int max_i=0,max_j=0,max_ele=-1;
	vector<vector<int> >dp(rows,vector<int>(columns,0));
	for(int i=0;i<rows;i++)
	{
		dp[0][i]=matrix[0][i];
	}
	for(int i=1;i<columns;i++)
	{
	  dp[i][0]=matrix[i][0];	
	}
	for(int i=1;i<rows;i++)
	{
		for(int j=1;j<columns;j++)
		{
			if(matrix[i][j]==1)
			{
				dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
				if(max_ele < dp[i][j])
				{
					max_ele=max(max_ele,dp[i][j]);
					max_i=i;
					max_j=j;
				}
				
			}
			else
			{
				dp[i][j]=0;
			}
		}
	}
	for(int i=max_i;i>max_i-max_ele;i--)
	{
		for(int j=max_j;j>max_j-max_ele;j--)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}

}
int main()
{
	vector<vector<int> >matrix;
	vector<int>v1,v2,v3,v4,v5,v6;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(0);
	v3.push_back(0);
	v3.push_back(1);
	v3.push_back(1);
	v3.push_back(1);
	v3.push_back(0);
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(0);
	v5.push_back(1);
	v5.push_back(1);
	v5.push_back(1);
	v5.push_back(1);
	v5.push_back(1);
	v6.push_back(0);
	v6.push_back(0);
	v6.push_back(0);
	v6.push_back(0);
	v6.push_back(0);
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);
	matrix.push_back(v5);
	matrix.push_back(v6);
	subSquareMatrix(matrix);
}
