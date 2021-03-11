#include<iostream>
using namespace std;
struct btnode
{
	int data;
	struct btnode* lc;
	struct btnode* rc;
};
typedef struct btnode* btptr;
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
btptr newNode(int d)
{
	btptr t=new struct btnode();
	t->lc=NULL;
	t->rc=NULL;
	t->data=d;
	return t;
}
int diameter(btptr t,int &ans)
{
	if(t==NULL)
	{
		return 0;
	}
	int ldiameter=diameter(t->lc,ans);
	int rdiameter=diameter(t->rc,ans);
	if(ans<ldiameter+rdiameter+1)
	{
		ans=ldiameter+rdiameter+1;
	}
	return max(ldiameter,rdiameter)+1;
	
}
int main()
{
	btptr root = newNode(1); 
    root->lc = newNode(2); 
    root->rc = newNode(3); 
    root->lc->lc = newNode(4); 
    root->lc->rc = newNode(5); 
    root->lc->rc->lc = newNode(6); 
    root->lc->rc->rc = newNode(7); 
    root->lc->lc->rc = newNode(8); 
    root->lc->lc->rc->lc = newNode(9); 
    int ans=0;
    int res=diameter(root,ans);
	cout<<"diameter is: "<<ans;
}
