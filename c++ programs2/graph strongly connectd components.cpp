#include<iostream>
#include<stack>
using namespace std;
int g[20][20];
void reverse(int g[20][20],int v)
{
	for(int i=1;i<=v;i++ )
	{
		for(int j=i;j<=v;j++)
		swap(g[j][i],g[i][j]);
	}
}
void DFS(int g[20][20],int visited[],int j,stack<int>&s,int v)
{
	visited[j]=1;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0 && g[j][i]==1)
		{
			DFS(g,visited,i,s,v);

			
		}
	}
		s.push(j);
}
void DFSUtil(int j,int visited[],int v)
{
	visited[j]=1;
	cout<<j<<" ";
	for(int i=1;i<=v;i++)
	{
	if(visited[i]==0 && g[j][i]==1)
	{
		DFSUtil(i,visited,v);
		}	
	}
}
void print(int g[20][20],stack<int >&s,int visited[],int v)
{	
while (s.empty() == false) 
    { 
        int i = s.top(); 
        s.pop();
        if (visited[i] == false) 
        { 
            DFSUtil(i, visited,v); 
            cout << endl; 
        } 
    } 	
}
void stronglyConnected(int g[20][20],stack<int>&s,int visited[],int v)
{
	for(int j=1;j<=v;j++)
	{
		if(visited[j]==0 )
		{
			DFS(g,visited,j,s,v);
		}
	}
	reverse(g,v);
	for(int i=1;i<=v;i++)
		visited[i]=0;
   
    print(g,s,visited,v);
	
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
