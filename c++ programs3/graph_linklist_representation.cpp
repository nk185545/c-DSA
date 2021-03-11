#include<iostream>
#include<stack>
using namespace std;
struct adjnode
{
	int data;
	struct adjnode* dptr;
	struct adjnode*next;
};
typedef struct adjnode* gptr;
gptr create_vertex_list(gptr t,int x)
{
	gptr temp;
   temp=new struct adjnode;
   temp->data=x;
   temp->dptr=temp->next=NULL;
   if(t==NULL)
   return temp;
   gptr ref=t;
   	while(ref->dptr!=NULL)
   	ref=ref->dptr;
   	ref->dptr=temp;
   	return t;
}
gptr create_edge_list(gptr t,int v1,int v2)
{
   gptr temp=t;
   while(temp->data!=v1)
   temp=temp->dptr;
   	while(temp->next!=NULL)
   	temp=temp->next;
   	gptr ref=new struct adjnode;
   	ref->data=v2;
   	ref->dptr=ref->next=NULL;
   	temp->next=ref;
   	return t;
}
void print_vertex_list(gptr t)
{
	while(t)
	{
		cout<<t->data<<" ";
		t=t->dptr;
	}
}
void print_edge_list(gptr t)
{
	while(t)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}
void print_graph(gptr t)
{

	if(t)
	{
	 gptr temp=t;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	print_graph(t->dptr);
}
}
}
int main()
{
  gptr root=NULL;
  int v1,v2,v,e;
  cout<<" Enter no. of vertecies and edges : "<<endl ;
	cin>>v>>e ;
	cout<<"Enter the vertaxs first : "<<endl ;
	for(int i=1 ;i<=v; i++)
	{
		int x ;
		cin>>x ;
		root = create_vertex_list(root,x) ;
	}
	cout<<"Vertex list : ";
	print_vertex_list(root) ;
	cout<<"\n Enter vertex1 and vertax2 combinations : "<<endl ;
	for(int i=1 ;i<=e ;i++)
	{
		cout<<"Enter v1 , v2 : "<<endl ;
		cin>>v1>>v2 ;
		root = create_edge_list(root,v1,v2) ;
	}
	print_edge_list(root);
	print_graph(root);
	return 0;
}
/*
5
8
1
2
3
4
5
1 2 
1 3
1 5
2 3
2 4
3 4
3 5
4 5
*/

