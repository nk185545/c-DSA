#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<queue>
using namespace std;
struct btnode
{
	char data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
 btptr create_node(char data )
 {
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = data;
		temp->lc = NULL ;
		temp->rc = NULL ;
		return temp ;
	}
void POST(btptr t)
{
	if( t )
	{
		POST(t->lc) ;
		POST(t->rc) ;
		cout<<t->data <<" "<<endl;
	}
}
int searchIndex(char inorder[],int instart,int inend,char d)
{
    for(int i=instart;i<=inend;i++)
    {
        if(inorder[i]==d)
        {
            return i;
        }
    }
}
btptr inorderToPreorder(btptr root,char preorder[],char inorder[],int instart,int inend,int &preindex)
{
 if(instart>inend)
 {
     return root;
     }
  root=create_node(preorder[preindex++]);
  int a=searchIndex(inorder,instart,inend,root->data);
  root->lc=inorderToPreorder(root->lc,preorder,inorder,instart,a-1,preindex);
  root->rc=inorderToPreorder(root->rc,preorder,inorder,a+1,inend,preindex);

}

int main()
{	btptr root = NULL ;
	int n ;
	char inorder[50],preorder[50] ;
	cout<<"Enter the n "<<endl;
	cin>>n;
	cout<<"Enter the inorder of elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>inorder[i] ;
	}
    cout<<"Enter the preorder of elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>preorder[i] ;
	}
int preindex=0;
	btptr t=inorderToPreorder(root,preorder,inorder,0,n-1,preindex) ;
   POST(t);
}
/*
15
ABD++E++CF++G++

15
AB+D+E+F+G++C++

19
AB+D+E+F++CGHI+++++

9
dbheiafcg
abdehicfg
*/
