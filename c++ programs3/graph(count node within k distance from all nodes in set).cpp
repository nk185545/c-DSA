#include<iostream>
#include<stack>
using namespace std;
int ans[50];
void dfs(int a,int g[20][20],int v,int visited[],int k,int d)
{
	visited[a]=1;
	if(d<=k)
	{
		ans[a]++;																											
	}
		for(int i=1;i<=v;i++)
		{
			if(g[a][i]==1 && visited[i]==0)
			{
				dfs(i,g,v,visited,k,d+1);
			}
		}
	
}
int main()
{
	int i,v,e,j,v1,v2,g[20][20],a;
	int visited[50]={0};
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
    int set;
    cout<<"enter the number of elements in the set:";
    cin>>set;
    int marked[set];
    int key,d=0;
    cout<<"enter elements: ";
    for(int i=0;i<set;i++)
    {
    	cin>>marked[i];
	}
	cout<<"Enter key : "<<endl;
	cin>>key ;
	for(int i=0;i<set;i++)
	{
		dfs(marked[i],g,v,visited, key,d);
        for(int j=0;j<50;j++)
		{
		visited[j]	=0;
		}
	}
		for(int i=1;i<=v;i++)
		{
		//	cout<<ans[i]<<" ";
			if(ans[i]==set)
			{
				cout<<i<<" ";
			}
		}
return 0;
}
/*
10 9
1 10
10 8
10 3
2 3
3 6
3 7
3 5
4 5
5 9
3
1 2 4
3
*/
