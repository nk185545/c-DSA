#include<iostream>
#include<stack>
using namespace std;
void DFS(int i,int visited[],int g[50][50],int v,stack<int>&s)
{
	visited[i]=1;
	for(int j=1;j<=v;j++)
	{
		if(g[i][j]==1 && visited[j]==0)
		{
			DFS(j,visited,g,v,s);
		}
	}
	s.push(i);
}
void reverse(int g[50][50],int v)
{
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			swap(g[j][i],g[i][j]);
		}
	}
}
void DFSUtil(int a,int g[50][50],int visited[],int v)
{
	visited[a]=1;
	cout<<a<<" ";
	for(int i=1;i<=v;i++)
	{
		if(g[a][i]==1 && visited[i]==0)
		{
			DFSUtil(i,g,visited,v);
		}
	}
}
void print(int g[50][50],int v,stack<int>&s,int visited[])
{
	while(!s.empty())
	{
		int a=s.top();
		s.pop();
		if(visited[a]==0)
		DFSUtil(a,g,visited,v);
		cout<<endl;
	}
}
void stronglyConnected(int g[50][50],stack<int>&s,int visited[],int v)
{
	for(int i=1;i<=v;i++)
	{
		DFS(i,visited,g,v,s);
	}
	reverse(g,v);
	for(int i=1;i<=v;i++)
	visited[v]=0;
	print(g,v,s,visited);
}
int main()
{
	int v;
	cout<<"enter number of vertices: ";
	cin>>v;
	int e;
	cout<<"enter number of edges: ";
	cin>>e;
	cout<<" enter edges: ";
	int v1,v2;
	int g[50][50];
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		  g[i][j]=0;
	}
	for(int i=0;i<e;i++)
	{
		cin>>v1>>v2;
		g[v1][v2]=1;
	}
	int visited[50];
	for(int i=1;i<=v;i++)
	visited[i]=0;
	stack<int>s;
	stronglyConnected(g,s,visited,v);
}
/*
5
5
2 1
1 3
3 2
1 4
4 5
*/
