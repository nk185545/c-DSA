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
 int checkSumTree(btptr t,int ll,int rl,int &sum)
 {
     if(t==NULL)
     {
         return 0;
     }
     if(t->lc==NULL && t->rc==NULL && t->data>=ll && t->data <= rl )
     {
     	sum=sum+t->data;
         return t->data;
     }
     if(t->data>=ll && t->data <= rl)
     sum=sum+t->data;
     int l=checkSumTree(t->lc,ll,rl,sum);
     int r=checkSumTree(t->rc,ll,rl,sum);
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
    int sum=0;
    int y=checkSumTree(root,3,10,sum);
    cout<<sum;
    return 0;
}
