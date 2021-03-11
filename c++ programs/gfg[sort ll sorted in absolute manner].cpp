#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node*next;
};
typedef struct node* lptr;
lptr create_linklist(lptr L,int x)
{	
		lptr temp,head;
		head=L;
		temp=new struct node();
		temp->data=x;
		temp->next=NULL;
		if(L==NULL)
		return temp;
	   while(L->next!=NULL)
	    L=L->next;
	    L->next=temp;
	    return head;
	    
}
lptr sort_ll(lptr head)
{
	lptr temp=head;
	lptr h=NULL;
	lptr test=NULL;
	while( temp->next !=NULL && temp!=NULL )
	{
		if(temp->next->data > 0)
		{
			temp=temp->next;
		}
		else
		{
			 h=temp->next;
			temp->next=temp->next->next;
			h->next=head;
			head=h;
		}
	}
	return head;
}
void printlist(lptr t)
{
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}
int main()
{
	lptr root1=NULL,root3=NULL;
	int x1,n;
	cout<<"enter number of nodes in link list ";
	cin>>n;
	cout<<"enter nodes of link list:\n";
	for(int i=0;i<n;i++)
	{
		cin>>x1;
		root1=create_linklist(root1,x1);
	}
//	printlist(root1);
	cout<<endl;
	root3=sort_ll(root1);
	printlist(root3);
}
