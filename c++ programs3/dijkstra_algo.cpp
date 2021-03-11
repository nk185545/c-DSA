#include<iostream>
#include<stack>
using namespace std;
int find_min(int visited[20],int d[20],int v)
{
	int min=INT_MAX,temp;
	for(int i=1;i<=v;i++)
	{
		if(min>d[i] && visited[i]==0)
		{
		 temp=i;
		 min=d[i];
		}
	}
	return temp;
}
void shortest_path(int g[20][20],int visited[20],int d[20],int x,int y,int v,int pv[20],int cv)
{
	int i=x;
	d[i]=0;
	while(i!=y)
	{
		for(int j=1;j<=v;j++)
		{
			if(g[i][j]>0&&visited[i]==0)
			{
				if(d[j]>d[i]+g[i][j])
				{
					d[j]=d[i]+g[i][j];
					pv[j]=i;
			}
			
			}
		}
		visited[i]=1;
		int new_i=find_min(visited,d,v);
		i=new_i;
	}
	stack<int>s;
	while(i!=x)
	{
		s.push(i);
		i=pv[i];
	}
	s.push(i);
	cout<<"shortest path between source and destination is: ";
	while(!s.empty())
	{
		if(s.size()==1)
		cout<<"v "<<s.top();
		else
		cout<<"v "<<s.top()<<"->";
		s.pop();
	}
	
}
int main()
{
	int g[20][20],visited[20],d[20],pv[20];
	int v,e,v1,v2,w;
	cout<<"enter vertices and edges ";
	cin>>v>>e;
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		g[i][j]=0;
	}
	cout<<"enter the edges b/w which edges exist(with weight) ";
	for(int k=1;k<=e;k++)
	{
		cin>>v1>>v2>>w;
		g[v1][v2]=w;
		g[v2][v1]=w;	
	}
	cout<<"adjency matrix is: ";
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
		cout<<g[i][j]<<" ";
	}
	cout<<endl;
	}
	int x, y;
	cout<<"enter source And destination vertex: ";
	cin>>x>>y;
	for(int i=1;i<=v;i++)
	{
		d[i]=1000000;
		visited[i]=0;
	}
     int cv=x;
	 shortest_path(g,visited,d,x,y,v,pv,cv);
	 return 0;	
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
4 5 2
4 7 4
4 6 8
4 3 2
*/
