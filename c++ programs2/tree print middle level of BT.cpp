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
void MiddleLevel(btptr t1,btptr t2)
{
    if(t2==NULL)
    {
        cout<<t1->data<<" ";
        return;
    }

    MiddleLevel(t1->lc,t2->lc->lc);
    MiddleLevel(t1->rc,t2->rc->rc);
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
    root->lc->lc->rc=newNode(5);
    root->lc->rc->lc=newNode(6);
    root->lc->rc->rc=newNode(9);
    root->rc->lc->lc=newNode(11);
    root->rc->lc->rc=newNode(15);
    root->rc->rc->lc=newNode(18);
    root->rc->rc->rc=newNode(20);
   btptr t=root;
   MiddleLevel(root,t);
    return 0;
}
