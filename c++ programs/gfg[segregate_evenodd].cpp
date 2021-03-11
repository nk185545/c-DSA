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
lptr segregate_evenodd(lptr l,int n)
{
	lptr head1=NULL,head2=NULL,temp=NULL,even=NULL,odd=NULL;
	temp=l;
	while(temp !=NULL)
	{
	if(temp->data%2==0)
	{
		if(head1==NULL)
		{
			head1=temp;
			even=head1;
		}
		else
		{
			even->next=temp;
			even=even->next;
		}
	}
	else
	{
		if(head2==NULL)
		{
			head2=temp;
			odd=head2;
			
		}
		else
		{
			odd->next=temp;
			odd=odd->next;
		}
	}
	temp=temp->next;
}
if(head1==NULL)
{
	return head2;
}
odd->next=NULL;
even->next=head2;
return head1;
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
	root3=segregate_evenodd(root1,n);
	printlist(root3);
}
