#include<iostream>
#include<vector>
using namespace std;
 void HamiltonianPath(vector<vector<int> >graph,vector<int> visited,int i,int cnt,vector<int>ans)
{
	ans.push_back(i);
	visited[i]=1;
	cnt++;
	int v=graph.size();
	if(cnt==v-1)
	{
		for(int k=0;k<ans.size();k++)
		{
			cout<<ans[k]<<" ";
		}
		int n=ans.size();
		if(graph[ans[0]][ans[n-1]]==1)
		{
			cout<<"there is an cycle : ";
			for(int k=0;k<ans.size();k++)
		{
			cout<<ans[k]<<" ";
		}
		cout<<" "<<ans[0]<<endl;
		}
		cout<<endl;
		return ;
	}
	for(int j=1;j<=v;j++)
	{
		if(graph[i][j]==1 && visited[j]==-1)
			HamiltonianPath(graph,visited,j,cnt,ans);
	}
}
int main()
{
	
	int v,e;
	vector<vector<int > >graph;
	cout<<"enter number of vertices: ";
	cin>>v;
	cout<<"enter number of edges : ";
	cin>>e;
	for(int i=0;i<=v;i++)
	{
		vector<int> vec;
		for(int j=0;j <=v;j++)
		{
			vec.push_back(0);
		}
		graph.push_back(vec);
	}
	cout<<"enter edges : ";
	int v1,v2;
	for(int i=1;i<=e;i++)
	{
		cin>>v1>>v2;
		graph[v1][v2]=1;
		graph[v2][v1]=1;
	}
	vector<int> visited;
	for(int i=0;i<=v;i++)
	{
		visited.push_back(-1);
	}
	vector<int>res;
	for(int i=1;i<=v;i++)
	HamiltonianPath(graph,visited,i,0,res);
}
/*
4
5
1 2
2 3
3 4
2 4
4 1
*/

