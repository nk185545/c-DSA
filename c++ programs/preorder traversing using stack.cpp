#include<iostream>
#include<stack>
using namespace std;
struct bstnode
{
	int data;
	struct bstnode *lc,*rc,*ptr;
};
typedef struct bstnode* bstptr;
bstptr getnewnode(int data)
{
	bstptr root=new struct bstnode();
	root->data=data;
	root->lc=NULL;
	root->rc=NULL;
	return root;
}
bstptr insertelement(bstptr root,int data)
{
	if(root==NULL)
	root=getnewnode(data);
	else if(data<=root->data)
	root->lc=insertelement(root->lc,data);
	else
	root->rc=insertelement(root->rc,data);
	return root;
}
void preorder(bstptr root)
{
	if(root==NULL)
	return;
	stack<bstnode*>s;
	s.push(root);
	while(!s.empty())
   {
	bstptr temp=s.top();
	cout<<temp->data<<endl;
	s.pop();
	if(temp->rc)
	s.push(temp->rc);
	if(temp->lc)
	s.push(temp->lc);
	}		
}
void inorder(bstptr root)
{
	stack<bstnode*>s;
	bstnode* temp=root;
	while(temp!=NULL||s.empty()==false)
   {
	while((temp)!=NULL)
	{
	s.push(temp);
	temp=temp->lc;
    }
   temp=s.top();
   s.pop();
   cout<<temp->data<<endl;
temp=temp->rc;
}
}
void postorder(bstptr root)
{
	if(root==NULL)
	return;
	stack<bstnode*>s;
	s.push(root);
	while(!s.empty())
   {
	bstptr temp=s.top();
	cout<<temp->data<<endl;
	s.pop();
	if(temp->rc)
	s.push(temp->rc);
	if(temp->lc)
	s.push(temp->lc);
	}		
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
	cout<<"preorder is:";
	preorder(root);
	cout<<"inorder is:";
	inorder(root);
	cout<<"postorder is:";
	postorder(root);
	return 0;	
}
