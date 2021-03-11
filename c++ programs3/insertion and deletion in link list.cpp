#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
typedef struct node *lptr ;
lptr insertatending(lptr L , int data)
{
		lptr temp,head;
		head=L;
		temp=new struct node();
		temp->data=data;
		temp->next=NULL;
		if(L==NULL)
		return temp;
	   while(L->next!=NULL)
	    L=L->next;
	    L->next=temp;
	    return head;
	    
}
lptr insertatbeggining(lptr L,int data)
{
	lptr temp=new node();
	temp->data=data;
	temp->next=L;
    L=temp;
    return L;
}
lptr insertatparticular(lptr L,int data,int knowndata)
{
	lptr temp=new struct node();
	lptr head=L;
	temp->data=data;
	while(L->data!=knowndata)
	{
		L=L->next;
	}
   temp->next=L->next;
	L->next=temp;
	return head; 
}
lptr deletenodespecificposition(lptr L,int x)
{
	lptr head=L;
	if(L->next==NULL)
	{
	L=NULL;
}
lptr temp=L;
if(temp->data==x)
{
	temp=temp->next;
	L=temp;
	return L;
}
while(temp)
{
	if(temp->data==x)
	{
		temp->data=temp->next->data;
		temp->next=temp->next->next;
		break;
	}
	temp=temp->next;
}
return head;
}
lptr deletefrombeggining(lptr L)
{
	lptr temp;
	temp=L;
	temp=temp->next;
	return temp;
}
lptr deletefromending(lptr L)
{
	lptr temp=new struct node();
	lptr head;
	if(L==NULL)
	return NULL;
	temp=L;
	while(temp->next->next!=NULL)
	{
	temp=temp->next;
 }
 delete(temp->next);
 temp->next=NULL;
	return L;
	
}
void printlist( lptr L )
{   cout<<"link list elements are: "<<endl;
	while(L != NULL)
	{  
		cout<< L->data <<endl;
		L=L->next ;
	}	
}
int main()
{
	lptr L = NULL;
	lptr p;
	cout<<"Enter number of elements : "<<endl;
	int x,n,data,knowndata,d;
	cin>>n;
	int a[50];
	cout<<"Enter the elements of linked list : "<<endl;
	for(int i=0 ; i<n ; i++)
	{
		cin>>x;
	   L= insertatending( L ,x) ;
	 
	}
	  printlist(L);
	  cout<<"enter data which you want to insert"<<endl;
	  cin>>data;
	  cout<<"after which node you want to insert a new node:"<<endl;
	  cin>>knowndata;
	  L=insertatparticular(L,data,knowndata);
	  printlist(L);
	  cout<<"enter the data which you want to insert at beggining"<<endl;
	  cin>>data;
	  L=insertatbeggining(L,data);
	  printlist(L);
	 cout<<"after deletion from begginig"<<endl;
	  L=deletefrombeggining(L);
	  printlist(L);
	cout<<"enter the element which you want to delete\n";
	 cin>>d;
   	 L=deletenodespecificposition(L,d);
	 printlist(L);
	 L=deletefromending(L);
	 printlist(L);
	 return 0;
	
}
