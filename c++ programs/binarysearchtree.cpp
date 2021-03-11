#include<iostream>
#include<stdlib.h>
using namespace std;
struct BSTnode
{
	int data;
	BSTnode *lchild, *rchild;
};
BSTnode *getnewnode(int data)
{
	struct BSTnode* temp=new BSTnode();
	temp->data=data;
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;
}
BSTnode* insertelement( BSTnode* root,int data)
{
	if(root==NULL)
	root=getnewnode(data);
	else if(data<=root->data)
	root->lchild=insertelement(root->lchild,data);
	else 
	root->rchild=insertelement(root->rchild,data);
	return root;
}
BSTnode* minimumkey(BSTnode* curr)
{
	while(curr->lchild!=NULL)
	curr=curr->lchild;
	return curr;
}
void searchkey(BSTnode* curr,int key,BSTnode* parent)
{
	while(curr!=NULL && curr->data!=key)
	{
		parent=curr;
		if(key<curr->data)
		curr=curr->lchild;
		else
		curr=curr->rchild;
	}
}
void deletenode(BSTnode* root,int key)
{
	BSTnode*parent=NULL;
	BSTnode *curr=root;
	searchkey(curr,key,parent);
	if(curr==NULL)
	return;
	//case 1: node with 0 child
	if(curr->lchild==NULL &&curr->rchild==NULL)
	{
		if(curr!=root)
		{
			if(parent->lchild==curr)
			parent->lchild==NULL;
			else
			parent->rchild==NULL;
		}
		else
		root=NULL;
		free(curr);
	}
	//case 2: node with 2 child
	else if(curr->lchild && curr->rchild)
	{
	 BSTnode*successor=minimumkey(curr->rchild);
	 int val=successor->data;
	 deletenode(root,successor->data);
	 curr->data=val;
	}
	//case 3: node with 1 child
	else
	{
		
		BSTnode* child=(curr->lchild)?curr->lchild:curr->rchild;
		if(curr!=root)
		{
			if(curr==parent->lchild)
			parent->lchild=child;
			else
			parent->rchild=child;
		}
		else
		root=child;
		free(curr);
	}
	
}
void inorder(struct BSTnode* t)
{
	if(t)
	{
		inorder(t->lchild);
		cout<<t->data<<endl;
		inorder(t->rchild);
	}
}
int main()
{
	int n,data;
	struct BSTnode* root=NULL;
	cout<<"enter number of nodes in tree";
	cin>>n;
	cout<<"enter data\n";
	for(int i=0;i<n;i++)
	{ cin>>data;
		root=insertelement(root,data);
	}
	cout<<"inorder traversal is: ";
	inorder(root);
    deletenode(root,17);
    inorder(root);
}
//  15 10 20 27 17 7 5 12 19

