#include<iostream>
using namespace std;
struct BSTnode
{
	int data[3];
	BSTnode *lchild, *rchild;
};
BSTnode *getnewnode(int arr[],int d)
{
	struct BSTnode* temp=new BSTnode();
	for(int i=0;i<d;i++)
    {
        temp->data[i]=arr[i];
    }
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;
}
BSTnode* insertelement( BSTnode* root,int a[],int &p,int d)
{
	if(root==NULL)
    {
     root=getnewnode(a,d);
    }
	else if(a[p%d]> root->data[p%d])
    {
        p++;
       root->rchild= insertelement(root->rchild,a,p,d);
    }
    else
        {
        p++;
       root->lchild= insertelement(root->lchild,a,p,d);
    }
    return root;
}

void inorder(struct BSTnode* t,int d)
{
	if(t)
	{
		inorder(t->lchild,d);
		for(int i=0;i<d;i++)
        {
            cout<<t->data[i]<<" ";
        }
        cout<<endl;
		inorder(t->rchild,d);
	}
}
int main()
{
	int n;
	struct BSTnode* root=NULL;
	cout<<"enter number of nodes in tree";
	cin>>n;
	int d;
	cout<<"enter d: ";
	cin>>d;
	int a[d];
	cout<<"enter data\n";
	for(int i=0;i<n;i++)
    {
        for(int i=0;i<d;i++)
        {
            cin>>a[i];
        }
       int p=0;
		root=insertelement(root,a,p,d);
	}
	cout<<"inorder traversal is: ";
	inorder(root,d);
}
//  15 10 20 27 17 7 5 12 19

/* 8
  3
  15 13 19
  16 14 17
  10 11 12
  16 13 12
  9 10 7
  18 15 19
  20 12 19
  7 13 10
  */

