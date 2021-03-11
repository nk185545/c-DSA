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
bool compare_linklist(lptr root1,lptr root2,int n1,int n2)
{
	lptr t1=NULL,t2=NULL;
	t1=root1;
	t2=root2;
   if(n1!=n2)
   {
   	return false;
	} 
	else if(n1==n2 && root1!=NULL && root2!=NULL)
	{
		while(t1!=NULL)
		{
			if(t1->data==t2->data)
			{
			t1=t1->next;
			t2=t2->next;
			}
			else
			{ 
			return false;
			}
		}
	}
return true;	
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
	lptr root1=NULL,root2=NULL;
	bool b;
	int x1,x2,n1,n2;
	cout<<"enter number of nodes in link list one and two: ";
	cin>>n1>>n2;
	cout<<"enter nodes of first link list:\n";
	for(int i=0;i<n1;i++)
	{
		cin>>x1;
		root1=create_linklist(root1,x1);
	}
	printlist(root1);
	cout<<"\nenter nodes of second link list:";
	for(int i=0;i<n2;i++)
	{
		cin>>x2;
		root2=create_linklist(root2,x2);
	}
	printlist(root2);
	cout<<endl;
	b=compare_linklist(root1,root2,n1,n2);
	cout<<b;
	return 0;
}
