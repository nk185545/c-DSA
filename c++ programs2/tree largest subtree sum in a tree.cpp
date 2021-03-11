#include<iostream>
using namespace std;
struct btnode
{
	int data;
	struct btnode* lc;
	struct btnode* rc;
};
typedef struct btnode* btptr;
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
btptr newNode(int d)
{
	btptr t=new struct btnode();
	t->lc=NULL;
	t->rc=NULL;
	t->data=d;
	return t;
}
int largestSum(btptr t,int &maxSum)
{
	if(t==NULL)
	return 0;                                                                                                                                                                                                                                               
	int l=largestSum(t->lc,maxSum);
	int r=largestSum(t->rc,maxSum);
	if(l+r+t->data >maxSum)
	{
		maxSum=l+r+t->data;
	}
	return l+r+t->data;
	
 } 
int main()
{
	btptr root = newNode(1); 
    root->lc = newNode(-2); 
    root->rc = newNode(3); 
    root->lc->lc = newNode(4); 
    root->lc->rc = newNode(5); 
    root->rc->lc = newNode(-6); 
    root->rc->rc = newNode(2); 
//    root->lc->lc->rc = newNode(8); 
  //  root->lc->lc->rc->lc = newNode(9); 
    int sum=0;
    int max_sum=INT_MIN;
    int ans=largestSum(root,max_sum);
	cout<<"sum : "<<max_sum;
}
