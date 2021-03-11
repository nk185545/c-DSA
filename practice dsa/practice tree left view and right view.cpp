#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<queue>
using namespace std;
struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
btptr Node(int x)
{
	btptr t=new struct btnode();
	t->data=x;
	t->lc=NULL;
	t->rc=NULL;
}
void rightView(btptr t,int l)
{
	static int max=0;
	if(t==NULL)
	return;
	if(max < l)
	{
		cout<<t->data<<" ";
		max=l;
	}
	rightView(t->rc,l+1);
	rightView(t->lc,l+1);
}
void leftView(btptr t,int l)
{
	static int max=0;
	if(t==NULL)
	return; 
	if(max < l)
	{
		cout<<t->data<<" ";
		max=l;
	}
	leftView(t->lc,l+1);
	leftView(t->rc,l+1);
}
int main()
{
	btptr root = Node(20); 
    root->lc =  Node(8); 
    root->rc =  Node(22); 
    root->lc->lc =  Node(5); 
    root->lc->rc =  Node(3); 
    root->rc->lc =  Node(4); 
    root->rc->rc =  Node(25); 
    root->lc->rc->lc =  Node(10); 
    root->lc->rc->rc = Node(14); 
    cout << "left view of the given binary tree :\n";
    leftView(root,1); 
    cout<<" right view of the given binary tree is:  ";
    rightView(root,1);
    return 0; 
}
