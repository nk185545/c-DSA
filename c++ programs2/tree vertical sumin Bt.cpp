#include<iostream>
#include<map>
#include<iterator>
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
void verticalSum(btptr t,int h,map<int,int>&mp)
{
	if(t==NULL)
	return ;
	verticalSum(t->lc,h-1,mp);
	mp[h]+=t->data;
	verticalSum(t->rc,h+1,mp);
}
int main()
{
	btptr root = newNode(1); 
    root->lc = newNode(2); 
    root->rc = newNode(3); 
    root->lc->lc = newNode(4); 
    root->lc->rc = newNode(5); 
    root->rc->lc = newNode(6); 
    root->rc->rc = newNode(7); 
//    root->lc->lc->rc = newNode(8); 
  //  root->lc->lc->rc->lc = newNode(9); 
    int h=0;
    int i=0;
    map<int,int>mp;
    verticalSum(root,h,mp);
    map<int ,int> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
    	cout<<it->first<<" "<<it->second<<endl;
	}
	// cout<<"sum : "<<max_sum;
}
