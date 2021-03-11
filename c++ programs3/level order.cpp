#include<iostream>
#include<queue>
using namespace std;
struct bstnode
{
	int data;
	struct bstnode* lc;
	struct bstnode*rc;
};
typedef struct bstnode* bstptr;
bstptr levelorder(bstptr root)
{
	queue<bstnode*>q;
	if(root==NULL)
	return NULL;
	q.push(root);
	while(!q.empty())
	{
		bstptr current;
		current=q.front();
		cout<<current->data<<" ";
		if(current->lc!=NULL)
		q.push(current->lc);
		if(current->rc!=NULL)
		q.push(current->rc);
		q.pop();
	}
}
bstptr getnewnode(int data)
{
	bstptr temp= new struct bstnode();
	temp->data=data;
	temp->lc=NULL;
	temp->rc=NULL;
	return temp;
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
int main()
{
	bstptr root=NULL;
	int n,data;
	cout<<"enter number of nodes in tree "<<endl;
	cin>>n;
	cout<<"enter tree elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>data;
	root=insertelement(root,data);
}
cout<<"level order is: ";
	levelorder(root);
return 0;	
}
 //15 10 20 27 17 7 5 12 19
