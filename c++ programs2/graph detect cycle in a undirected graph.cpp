#include<iostream>
#include<queue>
#include<map>
using namespace std;
bool BFS(queue<int>q,int a,int visited[],int g[][20],int v)
{
	int parent[v+1];
	visited[a]=1;
	q.push(a);
		while(!q.empty())
	{
		int t=q.front();
	    q.pop();
	    for(int i=1;i<=v;i++)
	    {
	    	if(visited[i]==0 && g[t][i]==1)
	    	{
	    		visited[i]=1;
	    		q.push(i);
	    	 parent[i]=t;	
			}
		else if(parent[t]!=i && g[t][i]==1)
  	       {
  		   return true;
	      }
	  }
}
 return false;
}
void detectcycle(int g[][20],int visited[],int a,int v)
{
	queue<int>q;
	bool ans=false;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0)
		{
		ans=BFS(q,i,visited,g,v);	
		}	   	
	}
	if(ans==true)
	cout<<"loop detected ";
	else
	{
		cout<<"loop not detected";
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
		g[v2][v1]=1;
	}
	int visited[v];
	for(int i=1;i<=v;i++)
	{
		visited[i]=0;
	}
	detectcycle(g,visited,1,v);
}
/* 
6
5
1 2
2 3
3 4
4 5
5 6

*/
	
