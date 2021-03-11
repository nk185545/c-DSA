#include<iostream>
using namespace std;
int g[50][50];
bool assign(int v,int color[],int i,int m)
{
	int flag[m+1]={0};
	for(int j=1;j<=v;j++)
	{
		if(g[i][j]==1 && color[j]!=0)
		{
			flag[color[j]]=1;
		}
	}
	for(int k=1;k<=m;k++)
	{
		if(flag[k]==0)
		{
			color[i]=k;
			return true;
		}
	}
	return false;
}
bool graphColoring(int v,int color[],int i,int m,int &cnt)
{
	if(assign(v,color,i,m))
	{
	cnt++;
   }
	for(int j=1;j<=v;j++)
	{
		if(g[i][j]==1 && color[j]==0 && graphColoring(v,color,j,m,cnt))
		return true;
		if(cnt==v)
		return true;
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
	int color[v+1];
	for(int i=1;i<=v;i++)
	{
		color[v]=0;
	}
	int m;
	cout<<"enter number of colors given: ";
	cin>>m;
	int cnt=0;
	bool bl=graphColoring(v,color,1,m,cnt);
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
