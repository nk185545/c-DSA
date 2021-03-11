#include<iostream>
#include<queue>
using namespace std;
int bfs(int t,int g[20][20])
{
	int v,u;
	int visited[50]={0};
	queue<int>q;
	visited[t]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		cout<<t<<" ";
	    q.pop();
	    for(int i=1;i<=v;i++)
	    {
	    	if(visited[i]==0 && g[t][i]==1)
	    	{
	    		visited[i]=1;
	    		q.push(i);
			}
		}
	}	
}
int main()
{
	int i,v,e,j,v1,v2,g[20][20],a;
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
    bfs(1,g);
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
