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
 int checkSumTree(btptr t,bool &x)
 {
     if(t==NULL)
     {
         return 0;
     }
     if(t->lc==NULL && t->rc==NULL)
     {
         return t->data;
     }
     int l=checkSumTree(t->lc,x);
     int r=checkSumTree(t->rc,x);
     if(t->data!=l+r)
     {
         x=false;
     }
      return t->data+r+l;
 }
int main()
{	btptr root = newNode(25);
    root->lc        = newNode(10);
    root->rc       = newNode(3);
   // root->rc->lc  = newNode(2);
    root->lc->rc = newNode(6);
    root->rc->rc = newNode(3);
    root->lc->lc=newNode(4);
    bool x=true;
    int y=checkSumTree(root,x);
    cout<<x;
    return 0;
}
