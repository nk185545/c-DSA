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
void postorder(bstptr root)
{
	bstptr curr=root;
	stack<bstnode*>s;
	while(true)
   {
   	if(curr!=NULL)
   	{ 
   	s.push(curr);
   	curr=curr->lc;
   }
   else
   {
   	if(s.empty())
   	break;
   	curr=s.top()->rc;
   	if(curr==NULL)
   	{
   		bstptr last=NULL;
   		while(!s.empty() && s.top()->rc==NULL)
   		{
   			cout<<s.top()->data<<endl;
   			s.pop();
   			
		   }
	   }
   }
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
	cout<<"postorder is:";
	postorder(root);
	return 0;	
}
// 15 10 20 27 17 7 5 12 19 
