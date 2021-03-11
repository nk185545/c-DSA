#include<iostream>
#include<vector>
#include<algorithm>
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
void identicalTree(btptr t1,btptr t2,bool &x)
{
    if((!t1 && t2) || (t1 && !t2))
    {
        x=false;
        return;
    }
    if(t1 == NULL && t2==NULL)
    {
        return;
    }
    if(t1->data != t2->data)
    {
        x=false;
        return;
    }
    identicalTree(t1->lc,t2->lc,x);
    identicalTree(t1->rc,t2->rc,x);
}
void subtree(btptr t1,btptr t2,bool &x)
{
    if(t1==NULL)
    {
        return;
    }
    if(t1 && t2 && t1->data == t2->data)
    {
        bool flag=true;
        identicalTree(t1,t2,flag);
        if(flag==true)
        {
        x=true;
        }
        return;
    }
    subtree(t1->lc,t2,x);
    subtree(t1->rc,t2,x);
}
int main()
{	btptr root = newNode(10);
    root->lc        = newNode(8);
    root->rc       = newNode(2);
    root->lc->lc  = newNode(3);
    root->lc->rc = newNode(5);
    root->rc->rc = newNode(7);
    root->rc->lc=newNode(9);
   /* root->lc->lc->lc=newNode(4);
    root->lc->lc->rc=newNode(5);
    root->lc->rc->lc=newNode(6);
    root->lc->rc->rc=newNode(9);
    root->rc->lc->lc=newNode(11);
    root->rc->lc->rc=newNode(15);
    root->rc->rc->lc=newNode(18);
    root->rc->rc->rc=newNode(20);*/
    btptr root2=newNode(8);
    root2->lc=newNode(3);
    root2->rc=newNode(9);
    bool b=false;
    subtree(root,root2,b);
    cout<<b;
    return 0;
}
