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
int main()
{	btptr root = newNode(10);
    root->lc        = newNode(8);
    root->rc       = newNode(2);
    root->rc->lc  = newNode(2);
    root->lc->rc = newNode(5);
    root->rc->rc = newNode(7);
    root->lc->lc=newNode(3);
    root->lc->lc->lc=newNode(4);
    btptr root2 = newNode(10);
    root2->lc        = newNode(8);
    root2->rc       = newNode(2);
    root2->rc->lc  = newNode(2);
    root2->lc->rc = newNode(6);
    root2->rc->rc = newNode(7);
    root2->lc->lc=newNode(3);
    root2->lc->lc->lc=newNode(4);
    bool x=true;
    identicalTree(root,root2,x);
    (x==true)? cout<<"both trees are identical" : cout<<"both trees are not identical";
    return 0;
}
