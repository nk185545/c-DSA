#include <iostream>
using namespace std;
struct btnode
{
	char data;
	struct btnode*lc;
	struct btnode*rc;
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
btptr create_tree(btptr t,char a[50],int &i,int n)
{
	if(i>=n)
	return t;
	t=create_node(t,a,i);
	if(t==NULL)
	{
	return NULL;
	}
	i++;
	t->lc=create_tree(t->lc,a,i,n);
	i++;
	t->rc=create_tree(t->rc,a,i,n);
}
btptr removenode(btptr root,char v)
{
    if(root==NULL)
    {
        return NULL;
    }
    root->lc=removenode(root->lc,v);
    root->rc=removenode(root->rc,v);
    if(root->data==v && root->lc==NULL && root->rc==NULL)
    {
        root=NULL;
    }
    return root;
}
void in(btptr t)
{
	if(t)
	{
		in(t->lc);
		cout<<t->data<<endl;
		in(t->rc);
	}
}
int main()
{
	btptr root=NULL;
	int n;
	char v;
	char a[50];
	cout<<"enter the total number of characters"<<endl;
	cin>>n;
	cout<<"enter the elements"<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int j=0;
	root=create_tree(root,a,j,n);
	cout<<"inorder is:  "<<endl;
	in(root);
	cout<<"enter the value(nodes with value will be deleted)"<<endl;
	cin>>v;
	removenode(root,v);
	in(root);
	return 0;
}

