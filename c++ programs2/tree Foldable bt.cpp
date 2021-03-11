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
bool foldableBT(btptr t1,btptr t2)
{
    if(t1==NULL && t2==NULL)
    {
        return true;

    }
    if(t1==NULL || t2==NULL)
    {

        return false;
    }

   return   foldableBT(t1->lc,t2->rc) && foldableBT(t1->rc,t2->lc);
}
int main()
{	btptr root = newNode(3);
    root->lc        = newNode(2);
    root->rc       = newNode(4);
    root->rc->lc  = newNode(1);
    root->lc->rc = newNode(3);
   // root->rc->rc = newNode(5);
    foldableBT(root->lc,root->rc)?  cout << "Yes" : cout << "No";
    return 0;
}
