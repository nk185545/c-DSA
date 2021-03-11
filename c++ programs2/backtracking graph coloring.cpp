#include<iostream>
using namespace std;
int g[50][50];
bool issafe(int g[][50],int color[],int c,int v,int a)
{
	for(int i=1;i<=v;i++)
	{
		if(g[a][i]==1 && c==color[i])
		return false;
	}
	return true;
}
bool graphColoring(int g[][50],int m,int v,int color[],int i)
{
	
	if(i-1==v)
	return true;
	for(int j=1;j<=m;j++)
	{
		if(issafe(g,color,j,v,i))
		{
			color[i]=j;
		    if(graphColoring(g,m,v,color,i+1)==true)
		    return true;
		    color[i]=0;
	}
}
return false;
}
int main()
{
	int v,a,b;
	cout<<"enter number of nodes: ";
	cin>>v;
	cout<<"enter number of edges: ";
	int e;
	cin>>e;
	cout<<"enter the a and b: ";
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		g[a][b]=1;
		g[b][a]=1;
	}
	int m;
	cout<<"enter number of colors: ";
	cin>>m;
	int color[v];
	for(int i=1;i<=v;i++)
	color[i]=0;
	bool bl;
	bl= graphColoring(g,m,v,color,1);
	if(bl==true)
	{
		cout<<"colors can be assigned in the order: ";
		for(int i=1;i<=v;i++)
		cout<<color[i]<<" ";
	}
	else
	{
		cout<<"colours cant be assigned";
	}
}
/*
5
6
1 2
2 5
5 4
4 3
3 1
2 3
*/
