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
lptr reverselinklist(lptr current)
{
	lptr previous=NULL;
    lptr nextnode=NULL;
    while(current!=NULL)
    {
    	nextnode=current->next;
    	current->next=previous;
    	previous=current;
    	current=nextnode;
	}
	return previous;  	
}
lptr sort_ll(lptr l,int n)
{
	lptr head1=NULL,head2=NULL,temp=NULL,pos=NULL,neg=NULL;
	temp=l;
	while(temp !=NULL)
	{
	if(temp->data>=0)
	{
		if(head1==NULL)
		{
			head1=temp;
			pos=head1;
		}
		else
		{
			pos->next=temp;
			pos=pos->next;
		}
	}
	else
	{
		if(head2==NULL)
		{
			head2=temp;
			neg=head2;
			
		}
		else
		{
			neg->next=temp;
			neg=neg->next;
		}
	}
	temp=temp->next;
}
if(head2==NULL)
{
	return head1;
}
lptr head3=reverselinklist(head2);
temp=head3;
while(temp->next !=NULL)
{
	temp=temp->next;
}
pos->next=NULL;
temp->next=head1;
return head3;
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
	printlist(root1);
	cout<<endl;
	root3=sort_ll(root1,n);
	printlist(root3);
}
