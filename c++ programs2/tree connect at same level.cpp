#include<iostream>
#include<map>
#include<iterator>
using namespace std;
struct btnode
{
	char data ;
	struct btnode *lc ;
	struct btnode *rc ;
	struct btnode *next ;
};
typedef struct btnode *btptr ;
btptr create_node(btptr t , char a[50] ,int i)
 {
 	if(a[i] != '+')
	{
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = a[i] ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		temp->next = NULL ;
		return temp ;
	}
	else {	return NULL ;}
 }

btptr create_tree(btptr T , char a[50] ,int &i ,int n)
{
	if(i >= n)
	{
		return T ;
	}
	T = create_node(T , a ,i) ;
	if(T==NULL) return NULL;
	i++;
	T->lc = create_tree(T->lc , a ,i , n) ;
	i++;
	T->rc = create_tree(T->rc , a ,i ,n) ;
}
void connect(btptr t,map<int,btptr>&mp,int l,map<int,btptr>&mp2)
{
    if(t==NULL)
        return;
    if(mp[l]==NULL)
    {
       mp[l]=t;
       mp2[l]=t;
    }
    else
    {
        btptr temp=mp[l];
        temp->next=t;
        temp=temp->next;
        mp[l]=temp;
    }
    connect(t->lc,mp,l+1,mp2);
    connect(t->rc,mp,l+1,mp2);
}
void printlevels(map<int,btptr>&mp)
{
   map<int,btptr> ::iterator it;
   for(it=mp.begin();it!=mp.end();it++)
   {
    btptr t=it->second;
    while(t!=NULL)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<endl;
   }
}
void PRE(btptr t)
{
	if( t )
	{
	    btptr temp=t;
	    while(temp!=NULL)
        {
           cout<<temp->data <<" -> ";
           temp=temp->next;
        }
        cout<<endl;
		PRE(t->lc) ;
		PRE(t->rc) ;
	}
}
int main()
{	btptr root = NULL ;
	int n ;
	map<int,btptr>mp,mp2;
	char a[50] ;
	cout<<"Enter the n "<<endl;
	cin>>n;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}

	int j =0 ;
	root = create_tree( root ,a , j , n) ;
	connect(root,mp,0,mp2);
	printlevels(mp2);
	cout<<"PRE_ORDER IS : "<<endl;
	// PRE(root) ;

}
/*
25
ABD++EF++G++CH+IJ++K++L++
*/
