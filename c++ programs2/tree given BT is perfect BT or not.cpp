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
 int height(btptr t,int h)
 {
     if(t==NULL)
     {
         return 0;
     }
     int l=height(t->lc,h+1);
     int r=height(t->rc,h+1);
     if(l>r)
     {
         return l+1;
     }
     else{
            return r+1;
            }
 }
 void perfectBT(btptr t,int h,int level,bool &x)
 {
     if(t==NULL)
     {
         return ;
     }
     if(t->lc==NULL && t->rc==NULL && h!=level)
     {
         x= false;
         return;
     }
     if((t->lc !=NULL && t->rc==NULL) || (t->lc !=NULL && t->rc==NULL))
     {
         x=false;
         return;
     }
     perfectBT(t->lc,h,level+1,x);
     perfectBT(t->rc,h,level+1,x);
 }
int main()
{	btptr root = newNode(10);
    root->lc        = newNode(8);
    root->rc       = newNode(2);
    root->rc->lc  = newNode(2);
    root->lc->rc = newNode(5);
    root->rc->rc = newNode(7);
    root->lc->lc=newNode(3);
  //  root->lc->lc->lc=newNode(4);
    int l=1;
    int h=height(root,l);
    // cout<<h;
    bool x=true;
    perfectBT(root,h,l,x);
    cout<<x;
    return 0;
}
