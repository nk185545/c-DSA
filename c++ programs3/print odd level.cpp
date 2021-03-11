#include<iostream>
using namespace std;
struct btnode
{
	char data;
	struct btnode* lc;
	struct btnode* rc;
	int level;
};
typedef struct btnode*btptr;
btptr create_node(btptr t,char a[50],int &i,int l)
{
	if(a[i]!='+')
	{
		btptr temp=NULL;
		temp=new struct btnode;
		temp->data=a[i];
		temp->lc=NULL;
		temp->rc=NULL;
		temp->level=l;
		return temp;
	}
	else
	return NULL;
}
btptr create_tree(btptr t,char a[50],int &i,int n,int l)
{
	if(i>=n)
	return t;
	t=create_node(t,a,i,l);
	if(t==NULL)
	return NULL;
	i++;
	t->lc=create_tree(t->lc,a,i,n,l+1);
	i++;
	t->rc=create_tree(t->rc,a,i,n,l+1);
}
void in(btptr t)
{
	if(t)
	{
		in(t->lc);
		cout<<t->data<<" "<<t->level<<endl;
		in(t->rc);
	}
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int height(btptr t)
{
  if(t==NULL)
  {
  return 0;
}
else
{
	int ma=0;
  ma=max(height(t->lc),height(t->rc));
  return (ma+1);
}
}
btptr print_odd(btptr t,int i)
{
	if(t==NULL)
	{
		return t;
	}
	if(t->level==i)
	{
		cout<<t->data<<" ";
	}
	print_odd(t->lc,i);
	print_odd(t->rc,i);
}
int main()
{
	btptr root=NULL;
	int n,l=0,m;
	char a[50];
	cout<<"enter the total number of characters"<<endl;
	cin>>n;
	cout<<"enter the elements"<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int j=0;
	root=create_tree(root,a,j,n,l);
	m=height(root);
	cout<<m<<endl;
	cout<<"inorder is:  "<<endl;
	in(root);
	for(int i=0;i<m;i++)
	{
		if((i%2)==1)
		{
			print_odd(root,i);
		}
		cout<<endl;
	}
	return 0;
}
// abcd++e++++
