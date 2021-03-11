#include<iostream>
#include<stack>
#include<map>
using namespace std;
bool DFS(int a,int visited[],int g[][20],int v)
{
	visited[a]=1;
  for(int i=1;i<=v;i++)
  {
  	if(g[a][i]==1 && visited[i]==1)
  	{
  		cout<<"loop detected ";
  		cout<<i<<" "<<a<<endl;
  		return true;
	  }
	else if(g[a][i]==1 && visited[i]==0)
	{
		if(DFS(i,visited,g,v))
		{
			cout<<" "<<a<<endl;
		}
    }
	  }
	  return false;
}
void detectcycle(int g[][20],int visited[],int a,int v)
{
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0)
		{
		DFS(i,visited,g,v);	
		}	   	
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
	stack<int>s;
	int visited[v];
	for(int i=1;i<=v;i++)
	{
		visited[i]=0;
	}
	detectcycle(g,visited,1,v);
}
/* 
4
5
1 2
1 3
3 4
4 1
4 4

*/
	
