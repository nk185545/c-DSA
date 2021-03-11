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
bstptr LCA(bstptr root,int a,int b)
{
	bstptr t=root;
	if(root==NULL)
	return root;
	else if((a<t->data && b>t->data)||(a>t->data && b<t->data))
	cout<<"LCA IS:"<<t->data;
	else if((a<t->data&&b<t->data))
	return LCA(t->lchild,a,b);
	else if(a>t->data && b>t->data)
	return LCA(t->rchild,a,b);
	else
	cout<<"no common ansester";
}
int main()
{
	bstptr root=NULL;
	int n,data,item,a,b;
	cout<<"enter number of nodes in tree";
	cin>>n;
	cout<<"enter data\n";
	for(int i=0;i<n;i++)
	{
		cin>>data;
		root=insertelement(root,data);
	}
	cout<<"preorder is:";
	preorder(root);
	cout<<"enter two data (to find out lowest common anasester) \n";
	cin>>a>>b;
	LCA(root,a,b);
	return 0;	
}
