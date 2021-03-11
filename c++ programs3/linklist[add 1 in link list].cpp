#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* lptr; 
lptr create_linklist(lptr L,int x)
{
	lptr temp=new struct node();
	temp->data=x;
	temp->next=L;
	L=temp;
	return L;
}
lptr insertatending(int data)
{
		lptr temp=NULL,head=NULL;
		temp=new struct node();
		temp->data=data;
		temp->next=NULL;
	    return temp;
	    
}
lptr addone(lptr head)
{
	lptr temp=NULL;
	int sum=0;
	lptr root=NULL;
	root=head;
	int carry=1;
	while(head!=NULL)
	{
			int a=(head->data)%10;
			sum=head->data+carry;
			carry=sum>=10?1:0;
			sum=sum%10;
			head->data=sum;
			temp=head;
			head=head->next;
		}
			if(carry>0)
			{
				temp->next=insertatending(carry);
			}
			return root;
	
	}
lptr reverse_linklist(lptr head)
{
	lptr current=NULL,previous=NULL,nextnode=NULL;
	current=head;
	while(current!=NULL)
	{
		nextnode=current->next;
		current->next=previous;
		previous=current;
	    current=nextnode;	
	}
	return previous;
}

void printlist(lptr L)
{
	while(L)
	{
		cout<<L->data<<" ";
		L=L->next;
	}
}
int main()
{
	lptr root=NULL,head=NULL;
	int x,n;
	cout<<"enter the total nodes of link list: ";
	cin>>n;
	cout<<"\nenter nodes:  ";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		root=create_linklist(root,x);
	}
	printlist(root);
	cout<<endl;
	head=addone(root);
	printlist(head);
	return 0;
	
}
