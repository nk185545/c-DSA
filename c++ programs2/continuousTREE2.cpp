#include<iostream>
#include<queue>
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
void continuousTree(btptr t,bool &b)
{
    if(t==NULL)
    {
    	return;
	}
	if(t->lc!=NULL && abs(t->lc->data-t->data)!=1)
	{
		b=false;
		return;
	}
	if(t->rc!=NULL && abs(t->rc->data-t->data)!=1)
	{
		b=false;
		return;
	}
	continuousTree(t->lc,b);
	continuousTree(t->rc,b);
}
int main()
{	btptr root = newNode(3);
    root->lc        = newNode(2);
    root->rc       = newNode(4);
    root->lc->lc  = newNode(1);
    root->lc->rc = newNode(2);
    root->rc->rc = newNode(5);
    bool b=true;
    continuousTree(root,b);
    cout<<b;
    return 0;
}
