#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<queue>
using namespace std;
struct btnode
{
	char data ;
	int x_val ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
 btptr create_node(btptr t , char a[50] ,int i,int x)
 {
 	if(a[i] != '+')
	{
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = a[i] ;
		temp->x_val = x ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		return temp ;
	}
	else {	return NULL ;}
 }

btptr create_tree(btptr T , char a[50] ,int &i ,int n,int x)
{
	if(i >= n)
	{
		return T ;
	}
	T = create_node(T , a ,i,x) ;
	if(T==NULL) return NULL;
	i++;
	T->lc = create_tree(T->lc , a ,i , n,x+1) ;
	i++;
	T->rc = create_tree(T->rc , a ,i , n,x+1) ;
}
void PRE(btptr t)
{
	if( t )
	{
		cout<<t->data <<" "<<t->x_val<<endl;
		PRE(t->lc) ;
		PRE(t->rc) ;
	}
}
void TopView(btptr t,map<int,char > &mp)
{
	queue<btptr> q ;
	q.push(t) ;

	while(!q.empty())
	{
		btptr temp = q.front() ;
		q.pop() ;
        if(mp[temp->x_val]==0)
            mp[temp->x_val]=temp->data ;
		if(temp->rc) q.push(temp->rc) ;
		if(temp->lc) q.push(temp->lc) ;
	}

}

int main()
{	btptr root = NULL ;
	int n ;
	char a[50] ;
	cout<<"Enter the n "<<endl;
	cin>>n;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}

	 int j =0 ;
	 root = create_tree( root ,a , j , n,0) ;
	cout<<"PRE_ORDER IS : "<<endl;
	PRE(root) ;
	cout<<endl;
	map<int ,char > mp ;
	TopView(root,mp) ;

	map<int,char> :: iterator itr ;
	cout<<"top view is : "<<endl;
	for(itr=mp.begin() ; itr!=mp.end() ; itr++)
	{
		cout<<(itr->second) <<" ";
	}

}
/*
15
ABD++E++CF++G++

15
AB+D+E+F+G++C++

19
AB+D+E+F++CGHI+++++
*/
