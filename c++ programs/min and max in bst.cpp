#include<iostream>
using namespace std;
struct bstnode
{
	int data;
	struct bstnode* lchild,*rchild;
};
typedef struct bstnode* bstptr;
bstptr getnewnode(int data)
{
	bstptr temp=new bstnode();
	temp->data=data;
	temp->lchild=temp->rchild=NULL;
	return temp;
}
bstptr insertelement(bstptr root,int data)
{
	if(root==NULL)
	root=getnewnode(data);
	else if(data<=root->data)
	root->lchild=insertelement(root->lchild,data);
	else
	root->rchild=insertelement(root->rchild,data);
	return root;
}
void preorder(bstptr t)
{
	if(t)
	{
	cout<<t->data<<endl;
	preorder(t->lchild);
	preorder(t->rchild);
}
}
void min(bstptr root,int data)
{
	bstptr temp=root;
	while(temp->lchild!=NULL)
	{
		temp=temp->lchild;
	}
	cout<<"node with minimum value in tree is:"<<(temp->data)<<endl;
}
void max(bstptr root,int data)
{
	bstptr temp=root;
	while(temp->rchild!=NULL)
	temp=temp->rchild;
	cout<<"node with maximum value in tree is:"<<(temp->data)<<endl;
}
bstptr search(bstptr root ,int item)
{
	if(root==NULL)
	cout<<"item is not present";
	else if(item==root->data)
	cout<<"item is present\n";
	else if (item<root->data)
	{
	 return search(root->lchild,item);
	}
	else
	return search(root->rchild,item);
}
int main()
{
	bstptr root=NULL;
	int n,data,item;
	cout<<"enter number of nodes in tree";
	cin>>n;
	cout<<"enter data\n";
	for(int i=0;i<n;i++)
	{
		cin>>data;
		root=insertelement(root,data);
	}
	cout<<"enter the element which you want to search\n";
	cin>>item;
	cout<<"preorder is:";
	preorder(root);
	min(root,data);
	max(root,data);
	search(root,item);
	return 0;	
}
