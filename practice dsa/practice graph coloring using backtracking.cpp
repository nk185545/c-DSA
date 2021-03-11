#include<iostream>
using namespace std;
int g[50][50];
bool isSafe(int v,int color[],int m,int a,int j)
{
	for(int i=1;i<=v;i++)
	{
		if(g[a][i]==1 && color[i]==j)
		{
			return false;
		}
	}
	return true;
}
bool graphColoring(int v,int color[],int i,int m)
{
	if(i-1==v)
	{
		return true;
	}
	for(int j=1;j<=m;j++)
	{
		if(isSafe(v,color,m,i,j))
		{
			color[i]=j;
			graphColoring(v,color,i+1,m);
			return true;
		}
	}
	return false;
}
int main()
{
	int v,a,b,e;
	cout<<"enter v: ";
	cin>>v;
	cout<<"enter number of edges: ";
	cin>>e;
	cout<<"enter v1 and v2 : ";
	for(int i=1;i<=e;i++)
	{
		cin>>a>>b;
		g[a][b]=1;
		g[b][a]=1;
	}
	int color[v];
	for(int i=1;i<=v;i++)
	{
		color[v]=0;
	}
	int m;
	cout<<"enter number of colors given: ";
	cin>>m;
	bool bl=graphColoring(v,color,1,m);
	if(bl==true)
	{
		cout<<"graph can be colored in this mammer: ";
		for(int i=1;i<=v;i++)
		{
			cout<<color[i]<<" ";
		}
	}
	else
	{
		cout<<"graph can not be colored using m colors ";
	}
}
/*
5
6
1 2
2 5
2 3
1 3
3 4
4 5
*/
