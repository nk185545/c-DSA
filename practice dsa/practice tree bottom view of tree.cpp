#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<queue>
using namespace std;
struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
btptr Node(int x)
{
	btptr t=new struct btnode();
	t->data=x;
	t->lc=NULL;
	t->rc=NULL;
}
void print(btptr t,map<btptr ,int>&mp,int x)
{
	if(t==NULL)
	return;
	mp[t]=x;
	print(t->lc,mp,x-1);
	print(t->rc,mp,x+1);
}
void bottomView(btptr t)
{
	if(t==NULL)
	return;
	int x=0;
	map<btptr,int>mp;
	print(t,mp,x);
	queue<btptr>q;
	q.push(t);
	map<int,int>ans;
	while(!q.empty())
	{
		btptr temp=q.front();
		q.pop();
		ans[mp[temp]]=temp->data;
		if(temp->lc)
		{
			q.push(temp->lc);
		}
		if(temp->rc)
		{
			q.push(temp->rc);
		}
	}
	map<int,int>::iterator it;
	for(it=ans.begin();it!=ans.end();it++)
	{
		cout<<it->second<<" ";
	}
}
int main()
{
	btptr root = Node(20); 
    root->lc =  Node(8); 
    root->rc =  Node(22); 
    root->lc->lc =  Node(5); 
    root->lc->rc =  Node(3); 
    root->rc->lc =  Node(4); 
    root->rc->rc =  Node(25); 
    root->lc->rc->lc =  Node(10); 
    root->lc->rc->rc = Node(14); 
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root); 
    return 0; 
}
