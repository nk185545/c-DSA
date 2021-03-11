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
bool continuousTree(btptr t)
{
    queue<btptr>q;
    q.push(t);
    if(t==NULL)
    {

        return false;
    }
    while(!q.empty())
    {
        btptr a=q.front();
        q.pop();
        if(a->lc)
        {

           if(abs(a->lc->data - a->data)==1)
           {
            q.push(a->lc);
           }
            else{

                return false;
            }
        }
       if(a->rc)
       {

           if(abs(a->rc->data-a->data)==1)
           {
               q.push(a->rc);
           }
           else{
            return false;
           }
       }
    }
 return true;
}
int main()
{	btptr root = newNode(3);
    root->lc        = newNode(2);
    root->rc       = newNode(4);
    root->lc->lc  = newNode(1);
    root->lc->rc = newNode(3);
    root->rc->rc = newNode(5);
    continuousTree(root)?  cout << "Yes" : cout << "No";
    return 0;
}
