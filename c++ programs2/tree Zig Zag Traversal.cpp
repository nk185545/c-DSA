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
 int height(btptr root)
 {
     if(root==NULL)
     {
         return 0;
     }
  int lh=height(root->lc);
  int rh=height(root->rc);
  if(lh>=rh)
  {

      return 1+lh;
  }
  else{
    return 1+rh;
  }
 }
 void ZigZagTraversal(btptr t,vector<vector<int> >&v,int l)
 {
     if(t==NULL)
     {
         return;
     }
     v[l].push_back(t->data);
     ZigZagTraversal(t->lc,v,l+1);
     ZigZagTraversal(t->rc,v,l+1);

 }
 int main()
{	btptr root = newNode(3);
    root->lc        = newNode(2);
    root->rc       = newNode(2);
    root->rc->lc  = newNode(1);
    root->lc->rc = newNode(1);
    root->rc->rc = newNode(5);
    root->lc->lc=newNode(6);
    int h=height(root);
    vector<vector<int> >v;
    for(int i=0;i<h;i++)
    {

        vector<int> vec;
        v.push_back(vec);
    }
    ZigZagTraversal(root,v,0);
    int i=1;
	while(i<h)
	{
	    reverse(v[i].begin(),v[i].end());
	    i=i+2;
	}
	vector<int>ans;
	for(int j=0;j<h;j++)
	{
	    for(int k=0;k<v[j].size();k++)
	    {
	        cout<<v[j][k]<<" ";
	    }
	    cout<<endl;
	}

    return 0;
}
