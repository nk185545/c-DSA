#include<iostream>
using namespace std;
int G[50][50];
int v,e;
struct kru
{
	int v1,v2,w;
};
struct kru k[50];
void bubble_sort(struct kru k[])
{
	for(int i=1;i<=e;i++)
	{
		for(int j=1;j<=e-i-1;j++)
		{
			if(k[j].w>k[j+1].w)
			{
				struct kru temp=k[j];
				k[j]=k[j+1];
				k[j+1]=temp;
			}
		}
	}
}
bool check(int span[50][50],int v1,int v2,int w,int visited[],int &count)
{
    visited[v1]=1;
	if(v1==v2)
	{
		count++;
		return true;
	}
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0 && span[v1][i]>0)
		check(span,i,v2,w,visited,count);
	}
	if(count==0)
	return false;
}
void spanning_tree(int span[50][50])
{
int s=0;
while(s!=e)
{
	int a=k[s].v1;
	int b=k[s].v2;
	int w=k[s].w;
	int visited[50];
	int count=0;
	for(int i=1;i<=v;i++)
	visited[i]=0;
	bool x=check(span,a,b,w,visited,count);
	if(x==true)
	s++;
	else
	{
		cout<<s<<" ";
		span[a][b]=w;
		span[b][a]=w;
		s++;
	}
	}	
}
int main()
{
	cout<<"enter v and e  ";
	cin>>v>>e;
	int span[50][50];
	for(int i=1;i<=v;i++)
	for(int j=1;j<=v;j++)
	{
		span[i][j]=0;
		G[i][j]=0;
	 } 
	 int n=e;//heap_size=no. of edges
	 cout<<"enter v1 and v2 and w: ";
	 for(int l=1;l<=e;l++)
	 {int v1,v2,w;
	 	cin>>v1>>v2>>w;
	 	G[v1][v2]=w;
	 	G[v2][v1]=w;
	 	k[l-1].v1=v1;
	 	k[l-1].v2=v2;
	 	k[l-1].w=w;
	 }
	 cout<<"after sorting structure arrey is:";
	 bubble_sort(k);
	 for(int i=1;i<=v;i++)
	 {
	 	for(int j=1;j<=v;j++)
	 	{
	 		cout<<G[i][j]<<" ";
		 }
		 cout<<endl;
	 }
	 spanning_tree(span);
	 cout<<"spanning adjacency matrix is: ";
	  for(int i=1;i<=v;i++)
	 {
	 	for(int j=1;j<=v;j++)
	 	{
	 		cout<<span[i][j]<<" ";
		 }
		 cout<<endl;
	 }
	 int sum=0;
	  for(int i=1;i<=v;i++)
	 {
	 	for(int j=1;j<=v;j++)
	 	{
	 		sum=sum+span[i][j];
		 }
	}
cout<<"minimum cost spanning tree is: "<<sum<<endl;
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
4 5 7
4 7 4
4 6 8
4 3 2
*/
