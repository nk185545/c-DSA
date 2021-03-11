#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node*pnode;
	struct node*nnode;
};
typedef struct node* dlptr;
dlptr create_list(dlptr head,int data)
{
	dlptr temp=new struct node();
	dlptr l;
	temp->data=data;
	temp->pnode=NULL;
	temp->nnode=NULL;
	if(head==NULL)
	return temp;
	l=head;
	while(l->nnode!=NULL)
	l=l->nnode;
	temp->pnode=l;
	l->nnode=temp;
	return head;
}
dlptr specificpos(dlptr head,int x)
{
	dlptr temp=new struct node();
	dlptr l=head;
	temp->data=x;
	while(l->nnode!=NULL)
      {
      	if(temp->data>l->data && temp->data<l->nnode->data)
      	{
	        temp->nnode=l->nnode;
	        l->nnode=temp;	
		  }
	l=l->nnode;
         }
	return head;
}
dlptr showlist(dlptr head)
{
	dlptr temp;
	temp=head;
	cout<<"doubly link list elements atre: ";
	while(temp!=NULL)
    {
    	cout<<temp->data<<" ";
    	temp=temp->nnode;
    	
	}
}
int main()
{
	dlptr head=NULL;
	int data,n,beg,kd,d;
	cout<<"enter total number of elements in the doubly link list";
	cin>>n;
	cout<<"enter elements of link list ";
	for(int i=0;i<n;i++)
	{
		cin>>data;
		head=create_list(head,data);
	}
	showlist(head);
	cout<<"enter data:";
	cin>>d;
	head=specificpos(head,d);
	showlist(head);
	return 0;
}
