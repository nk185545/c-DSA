#include<iostream>
#include<stack>
using namespace std;
void dfs_traversal(int t,int g[20][20],int visited[20],int v)
{
	visited[t]=1;
	cout<<t<<" ";
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0 && g[t][i]==1)
		{
			dfs_traversal(i,g,visited,v);
		}
	}
	return;
}
int main()
{
	int i,v,e,j,v1,v2,g[20][20];
	int visited[20];
	for(int i=1;i<=v;i++)
	{
		visited[i]=0;
	}
	cout<<"enter the number of vertices of the graph: ";
	cin>>v;
	for(i=1;i<=v;i++)
	for(j=1;j<=v;j++)
	g[i][j]=0;
	cout<<"\n enter the number of edges in the graph ";
	cin>>e;
	cout<<"\nenter the vertices v1 and v2 between which edge exists";
	for(i=1;i<=e;i++)
	{
	cin>>v1>>v2;
	g[v1][v2]=1;
	g[v2][v1]=1;
}
dfs_traversal(1,g,visited,v);
for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		cout<<g[i][j]<<" ";
		cout<<endl;
	}
return 0;
}
/*
7
9
1 2
1 3
1 5
2 3
2 4
3 4
4 5
5 6
6 7
*/
