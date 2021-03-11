#include<iostream>
using namespace std;
int no_visit(int visited[20],int v)
{
	int x=0;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==1)
		x++;
	}
	return x;
}
void prim_MST(int g[20][20],int visited[20],int v)
{
	visited[1]=1;
	int t,p;
	int sum=0;
	int min=1000;
	while(no_visit(visited,v)!=v)
	{
		for(int i=1;i<=v;i++)
		{
			if(visited[i])
			{
			  for(int j=1;j<=v;j++)
			   {
				if(g[i][j]>0 && visited[j]==0)
				{
					if(min > g[i][j])
					{
						min=g[i][j];
						 t=i;
						 p=j;
					}
				}
			    }
		}
	}
		visited[p]=1;
 sum=sum+min;
 min=1000;
	cout<<"an edge from "<<t<<"  to  "<<p<<endl;
}
cout<<"minimum cost is: "<<sum;
}
int main()
{
	int i,v,e,j,v1,v2,w,g[20][20],a,visited[20]={0};
	cout<<"enter the number of vertices end edges of the graph: ";
	cin>>v>>e;
	for(i=1;i<=v;i++)
	for(j=1;j<=v;j++)
	g[i][j]=0;
	cout<<"\nenter the vertices v1 and v2 between which edge exists";
	for(i=1;i<=e;i++)
	{
	cin>>v1>>v2>>w;
	g[v1][v2]=w;
	g[v2][v1]=w;
}
for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		cout<<g[i][j]<<" ";
		cout<<endl;
	}
	prim_MST(g,visited,v);
}
/*
7 12
1 2 2
2 5 10
5 7 6
7 6 1
3 6 5
3 1 4
1 4 1
2 4 3
4 5 7
4 7 4
4 6 8
4 3 2
*/
