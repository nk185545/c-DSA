#include<iostream>
#include<map>
#include<cmath>
using namespace std;
struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
btptr newNode(int data )
 {
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = data ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		return temp ;

 }
int sumTree(btptr t)
{
    if(t==NULL)
    {
        return 0;
    }
    if(t->lc==NULL && t->rc==NULL)
    {
        
        return t->data;
    }
   int l=sumTree(t->lc);
   int r=sumTree(t->rc);
   int x=t->data;
   t->data=l+r;
   return x+l+r;
}
void pre(btptr t)
{
    if(t)
    {
        pre(t->lc);
        cout<<t->data<<" ";
        pre(t->rc);
    }
}
int main()
{	btptr root = newNode(10);
    root->lc        = newNode(-2);
    root->rc       = newNode(6);
    root->rc->lc  = newNode(8);
    root->lc->rc = newNode(-4);
    root->rc->rc = newNode(7);
    root->lc->lc=newNode(5);
    int x=sumTree(root);
    pre(root);
    return 0;
}
