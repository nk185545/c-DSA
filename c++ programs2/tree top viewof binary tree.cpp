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
void topViewofBT(btptr t,map<int,int>&mp,int l)
{
    if(t==NULL)
    {
        return;
    }
    if(mp[l]==0)
    {
    mp[l]=t->data;
    }
    topViewofBT(t->lc,mp,l-1);
    topViewofBT(t->rc,mp,l+1);

}
int main()
{	btptr root = newNode(1);
    root->lc        = newNode(2);
    root->rc       = newNode(3);
    root->rc->lc  = newNode(6);
    root->lc->rc = newNode(5);
    root->rc->rc = newNode(7);
    root->lc->lc=newNode(4);
    map<int,int>mp;
    topViewofBT(root,mp,0);
    map<int,int>::iterator i;
    for(i=mp.begin();i!=mp.end();i++)
    {
        cout<<i->second<<" ";
    }
    return 0;
}
