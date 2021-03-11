#include<iostream>
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
BSTnode* insertelement( struct BSTnode* root,int data)
{
	    root=getnewnode(data);
		for(int i=2;i<=data;i++)
		{
			if(data%i==0)
			{
				
			     root->lchild=getnewnode(i);
			    root->rchild=insertelement(root->rchild,(data/i));
			break;
		}
	}
	return root;
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
	int data;
	struct BSTnode* root=NULL;
	struct BSTnode*temp;
	temp->data=data;
	root=temp;
	cout<<"enter root node data\n";
	 cin>>data;
	root=insertelement(root,data);
	cout<<"inorder traversal is: ";
	inorder(root);
}


