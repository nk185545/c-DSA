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
lptr merge_linklist(lptr root1,lptr root2,int n)
{
	lptr t1=NULL,t2=NULL,temp=NULL;
	t1=root1;
	temp=t1;
	t2=root2;
	for(int i=0;i<2*n;i++)
	{
		if(i%2==0)
		{
		t1=t1->next;
		temp->next=t2;
		temp=temp->next;	
		}
		else
		{
			t2=t2->next;
			temp->next=t1;
			temp=temp->next;
		}
	}
	return root1;
	
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
	lptr root1=NULL,root2=NULL,root3=NULL;
	int x1,x2,n;
	cout<<"enter number of nodes in link list one and two: ";
	cin>>n;
	cout<<"enter nodes of first link list:\n";
	for(int i=0;i<n;i++)
	{
		cin>>x1;
		root1=create_linklist(root1,x1);
	}
	printlist(root1);
	cout<<"\nenter nodes of second link list:";
	for(int i=0;i<n;i++)
	{
		cin>>x2;
		root2=create_linklist(root2,x2);
	}
	printlist(root2);
	cout<<endl;
	root3=merge_linklist(root1,root2,n);
	printlist(root3);
}
