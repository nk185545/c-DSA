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
 int childSumProperty(btptr t,bool &x)
 {
     if(t==NULL)
     {
         return 0;
     }
     if(t->lc==NULL && t->rc==NULL)
     {
         return t->data;
     }
     int l=childSumProperty(t->lc,x);
     int r=childSumProperty(t->rc,x);
     if(t->data!=l+r)
     {
         x=false;
         return t->data;
     }
     return t->data;
 }
int main()
{	btptr root = newNode(10);
    root->lc        = newNode(8);
    root->rc       = newNode(2);
    root->rc->lc  = newNode(2);
    root->lc->rc = newNode(5);
    //root->rc->rc = newNode(7);
    root->lc->lc=newNode(3);
    bool x=true;
    int y=childSumProperty(root,x);
    cout<<x;
    return 0;
}
