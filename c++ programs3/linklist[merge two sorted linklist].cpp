#include<iostream>
using namespace std;
struct linklist
{
	int data;
	struct linklist* next;
};
typedef struct linklist* lptr;
lptr createlist(lptr L,int x)
{
	lptr temp,head;
		head=L;
		temp=new struct linklist();
		temp->data=x;
		temp->next=NULL;
		if(L==NULL)
		return temp;
	   while(L->next!=NULL)
	    L=L->next;
	    L->next=temp;
	    return head;
	    
}
lptr mergetwosortedll(lptr l1,lptr l2)
{
	lptr dummy=NULL;
	dummy=createlist(dummy,-1);
	lptr head=dummy;
	while(l1!=NULL && l2!=NULL)
	{
		if(l1->data <l2->data)
		{
			dummy->next=l1;
			l1=l1->next;
		}
		else
		{
			dummy->next=l2;
			l2=l2->next;
		}
		dummy=dummy->next;
	}
	while(l1!=NULL)
	{
		dummy->next =l1;
		l1=l1->next;
	}
	while(l2!=NULL)
	{
		dummy->next=l2;
		l2=l2->next;
	}
	return head->next;
}
int main()
{
	int n1,n2;
	lptr l1=NULL,l2=NULL,l3;
	cout<<"enter number of nodes in ll 1 and 2 respectively: ";
	cin>>n1>>n2;
	cout<<"enter values in linklist 1 :";
	for(int i=0;i<n1;i++)
	{
		int a;
		cin>>a;
		l1=createlist(l1,a);
	}
	cout<<"enter values in linklist 2 :";
	for(int i=0;i<n2;i++)
	{
		int a;
		cin>>a;
		l2=createlist(l2,a);
	}
  l3=mergetwosortedll(l1,l2);
  while(l3!=NULL)
  {
  	cout<<l3->data<<" ";
  	l3=l3->next;
  }
}
