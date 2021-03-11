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
 void print(int arr[],int n)
 {
     for(int i=0;i<=n;i++)
     {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
void pathToLeafPath(btptr t,int arr[],int i)
{
    if(t==NULL)
    {
        return;
    }
    if(t->lc==NULL && t->rc==NULL)
    {
        arr[i]=t->data;
        print(arr,i);
        return;
    }
    arr[i]=t->data;
    pathToLeafPath(t->lc,arr,i+1);
    pathToLeafPath(t->rc,arr,i+1);
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
    int arr[50];
    int i=0;
    pathToLeafPath(root,arr,i);
    return 0;
}
