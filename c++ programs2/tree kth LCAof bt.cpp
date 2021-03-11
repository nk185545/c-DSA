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
void search(btptr t,int y,bool &val)
{
	if(t)
	{
	if(t->data==y)
	{
		val=true;
		return;
	}
	search(t->lc,y,val);
	search(t->rc,y,val);
  }
}
btptr newNode(int data )
 {
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = data ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		return temp ;

 }
bool LCA(btptr t,int x,int y,bool &b,int &k,int &ans)
{
    if(t==NULL)
     return false;
//    if(t->data==x || t->data==y)
//    {
//    	
//    	return true;
//	}
    if(t->data==x)
	{
	  bool val=false;
	  search(t,y,val);
	  if(val==true)
	  {
	  	k--;
	  	if(k==0)
	  	{
	  		ans=t->data;
	    }
	    b=true;
	}	
	return true;
	}    
	 if(t->data==y)
	{
	  bool val=false;
	  search(t,x,val);
	  if(val==true)
	  {
	  	k--;
	  	if(k==0)
	  	{
	  		ans=t->data;
	    }
	    b=true;
	}	
	return true;
	}    
    bool l=LCA(t->lc,x,y,b,k,ans);
    bool r= LCA(t->rc,x,y,b,k,ans);
   if(l && r)
   {
     k--;
     if(k==0)
   	 {
   		ans=t->data;
   		return true;
 	}
    b=true;
    return true;
   }
   if(l || r)
   {
   	 if(b==true)
   	 {
   	 	k--;
   	 	if(k==0)
   		{
   		 ans=t->data;
 		}
	 }
   	 return true;
   }
   return false;
}
int main()
{	btptr root = newNode(10);
    root->lc        = newNode(8);
    root->rc       = newNode(2);
    root->rc->lc  = newNode(99);
    root->lc->rc = newNode(5);
    root->rc->rc = newNode(7);
    root->lc->lc=newNode(3);
    root->lc->lc->lc=newNode(4);
    root->lc->lc->rc=newNode(55);
    root->lc->rc->lc=newNode(6);
    root->lc->rc->rc=newNode(9);
    root->rc->lc->lc=newNode(11);
    root->rc->lc->rc=newNode(15);
    root->rc->rc->lc=newNode(18);
    root->rc->rc->rc=newNode(20);
    bool h=false;
    int k;
    cin>>k;
    int ans=-1;
    h=LCA(root,55,3,h,k,ans);
    if(h==true)
    {
    	cout<<ans;
	}
}
