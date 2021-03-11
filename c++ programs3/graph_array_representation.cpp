#include<iostream>
using namespace std;
int main()
{
	int i,v,e,j,v1,v2,g[20][20],a,indegree[50]={0},outdegree[50]={0};
	cout<<"enter the number of vertices end edges of the graph: ";
	cin>>v>>e;
	for(i=1;i<=v;i++)
	for(j=1;j<=v;j++)
	g[i][j]=0;
	cout<<"\nenter the vertices v1 and v2 between which edge exists";
	for(i=1;i<=e;i++)
	{
	cin>>v1>>v2;
	g[v1][v2]=1;
}
for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		cout<<g[i][j]<<" ";
		cout<<endl;
	}
/*	for(i=1;i<=v;i++)
	for(j=1;j<=v;j++)
	{
		if(g[i][j]==1)
		{
	
		outdegree[i]++;
		indegree[j]++;
	}
}
	for(int j=1;j<=v;j++)
	{
	 cout<<"indegree of v"<<j<<" is: "<<indegree[j]<<endl;	
	}
	for(int i=1;i<=v;i++)
	{
	 cout<<"outdegree of v"<<i<<" is: "<<outdegree[i]<<endl;	
	}*/
	cout<<"transpose of graph is: ";
	for(i=1;i<=e;i++)
	{
	g[v2][v1]=g[v1][v2];
}
for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		cout<<g[j][i]<<" ";
		cout<<endl;
	}
return 0;
}
/*
7 12
1 2 
2 5 
5 7 
7 6 
3 6 
3 1 
1 4 
2 4 
4 5 
4 7 
4 6 
4 3 
*/
