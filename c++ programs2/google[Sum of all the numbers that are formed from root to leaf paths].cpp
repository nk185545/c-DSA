#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node*left;
	struct node*right;
};
typedef struct node* btptr;
btptr newNode(int val)
{
	btptr root=new struct node();
	root->data=val;
	root->left=NULL;
	root->right=NULL;
	return root;
}
int treePathUtil(btptr root,int sum)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL && root->right==NULL)
	{
		sum=sum*10+root->data;
		return sum;
	}
	sum=sum*10+root->data;
	int lc=treePathUtil(root->left,sum);
	int rc=treePathUtil(root->right,sum);
	return lc+rc;
}
void treePathSum(btptr root)
{
	if(root==NULL)
	{
		return;
	}
	int sum=0;
	int ans=treePathUtil(root,sum);
	cout<<ans;
}
int main()
{
 	btptr root = newNode(6);  
    root->left = newNode(3);  
    root->right = newNode(5);  
    root->left->left = newNode(2);  
    root->left->right = newNode(5);  
    root->right->right = newNode(4);  
    root->left->right->left = newNode(7);  
    root->left->right->right = newNode(4);  
	treePathSum(root);	
}
