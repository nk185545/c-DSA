#include<iostream>
using namespace std;
int g[50][50];
bool assign(int color[],int v,int m,int i)
{
	int flag[m+1]={0};
	for(int j=1;j<=v;j++)
	{
	  if(g[i][j]==1 && color[j]!=0)
	  flag[color[j]]=1;	
	}
	for(int k=1;k<=m;k++)
	{
		if(flag[k]==0)
		{
			color[i]=k;
			return true;
		}		
	}
	return false;
}

bool graphColoring(int g[][50],int m,int v,int color[],int i,int &cnt)
{ 	
    
	if(assign(color,v,m,i))
	cnt++;
	for(int j=1;j<=v;j++)
	{
		if(g[i][j]==1 && color[j]==0  && graphColoring(g,m,v,color,j,cnt))
		return true;
		if(cnt==v)
	    return true; 			
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
	int cnt=0;
	int color[v+1];
	for(int i=1;i<=v;i++)
	color[i]=0;
	bool bl;
	bl= graphColoring(g,m,v,color,1,cnt);
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
