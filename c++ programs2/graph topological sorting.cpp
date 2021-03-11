#include<iostream>
#include<stack>
using namespace std;
void topo(int g[][20],int visited[],int a,stack<int>&s,int v)
{
	visited[a]=1;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0 && g[a][i]==1)
		{
			topo(g,visited,i,s,v);
		}
	}
		s.push(a);
}
void topologicalSorting(int g[][20],int v)
{
	int visited[v];
   for(int i=1;i<=v;i++)
	{
		visited[i]=0;
	}
	stack<int>s;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0)
		{
			topo(g,visited,i,s,v);
		}
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
int main()
{
	int v,e;
	int g[20][20];
	cout<<"enter number of vertices: ";
	cin>>v;
	cout<<"enter number of edges : ";
	cin>>e;
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			g[i][j]=0;
		}
	}
	cout<<"enter edges : ";
	int v1,v2;
	for(int i=1;i<=e;i++)
	{
		cin>>v1>>v2;
		g[v1][v2]=1;
	}
	int visited[v];
	
	topologicalSorting(g,v);
}
/*
6
6
5 1
5 2
4 2
3 4
6 2
6 1
*/

