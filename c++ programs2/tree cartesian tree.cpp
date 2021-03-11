#include<iostream>
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
 int findMax(int arr[8],int l,int h,int n)
 {
     int maxmium=INT_MIN;
     int ans=0;
     for(int i=l;i<=h;i++)
     {
         if(arr[i]>maxmium)
         {
            maxmium=arr[i];
            ans=i;
         }
     }
     return ans;
 }
 void IN(btptr t)
 {
     if(t)
     {
       IN(t->lc);
       cout<<t->data<<" ";
       IN(t->rc);
     }
 }
 btptr createCartesian(btptr t,int arr[8],int l,int h,int n)
 {
     if(l<=h)
     {
         int a=findMax(arr,l,h,n);
         t=newNode(arr[a]);
         t->lc=createCartesian(t->lc,arr,l,a-1,n);
         t->rc=createCartesian(t->rc,arr,a+1,h,n);
     }
     return t;
 }
 int main()
 {
     btptr t=NULL;
     btptr root=NULL;
     int arr[8]={1,5,10,40,30,15,28,20};
     int n=8;
     int l=0;int h=n-1;
     root=createCartesian(t,arr,l,h,n);
     IN(root);
 }
