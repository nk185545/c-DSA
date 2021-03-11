#include<iostream>
#include<vector>
using namespace std ;
void printAllPaths(int mat[2][3],int i,int j,int m,int n,vector<int>v)
{
	if(i>=m || j>=n)
	{
		return;
	}
		v.push_back(mat[i][j]);
	if(i==m-1 && j==n-1)
	{
		for(int k=0;k<v.size();k++)
		{
			cout<<v[k]<<" ";
		}
		cout<<endl;
	}
	printAllPaths(mat,i,j+1,m,n,v);
	printAllPaths(mat,i+1,j,m,n,v);
}
int main()
{
	int mat[2][3] = { {1, 2, 3}, {4, 5, 6} }; 
	int m=2 ;
	int n=3 ;
	vector<int>vec;
	printAllPaths(mat,0,0,m,n,vec);
}
