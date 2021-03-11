#include<iostream>
#include<stack>
using namespace std;
int dfs_traversal(int t,int g[20][20])
{
	int v;
	stack<int>s;
    int visited[20]={0};
    s.push(t);
    while(!s.empty())
    {
    	t=s.top();
    	s.pop();
    	if(visited[t]==0)
    	{
    		cout<<t<<" ";
    		visited[t]=1;
		}
		for(int i=1;i<=v;i++)
		{
			if(visited[i]!=1 && g[t][i]==1)
			{
			s.push(i);
		}
	}
	}
	cout<<endl;
}
int main()
{
	int i,v,e,j,v1,v2,g[20][20];
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
dfs_traversal(1,g);
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
