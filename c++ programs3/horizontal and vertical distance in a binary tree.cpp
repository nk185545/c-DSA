#include<iostream>
using namespace std;
struct btnode
{
	char data;
	struct btnode*lc;
	struct btnode*rc;
	int x_value;
	int y_value;
};
typedef struct btnode*btptr;
btptr create_node(btptr t,char a[50],int &i)
{
	if(a[i]!='+')
	{
		btptr temp=NULL;
		temp=new struct btnode;
		temp->data=a[i];
		temp->lc=NULL;
		temp->rc=NULL;
		return temp;
	}
	else
	return NULL;
}
btptr create_tree(btptr t,char a[50],int &i,int n,int x,int y)
{
	if(i>=n)
	return t;
	t=create_node(t,a,i);
	if(t==NULL)
	return NULL;
	t->x_value=x;
	t->y_value=y;
	i++;
	t->lc=create_tree(t->lc,a,i,n,x-1,y+1);
	i++;
	t->rc=create_tree(t->rc,a,i,n,x+1,y+1);
}
void in(btptr t)
{
	if(t)
	{
		in(t->lc);
		cout<<t->data<<" "<<t->x_value<<" "<<t->y_value<<endl;
		in(t->rc);
	}
}
int main()
{
	btptr root=NULL;
	int n;
	int x=0;
	int y=0;
	char a[50];
	cout<<"enter the total number of characters"<<endl;
	cin>>n;
	cout<<"enter the elements"<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int j=0;
	root=create_tree(root,a,j,n,x,y);
	cout<<"inorder is:  "<<endl;
	in(root);
	return 0;
}
// abd++e++cf++g++
