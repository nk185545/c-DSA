#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
typedef struct node* lptr;
lptr temp;
lptr front=NULL;
lptr rear=NULL;
void insertelement(int x)
{
	if(rear==NULL)
	{
		rear=new node();
	    rear->next=NULL;
		rear->data=x;
		front=rear;
	}
	else
	{
		temp=new node();
		rear->next=temp;
		temp->data=x;
		temp->next=NULL;
		rear=temp;
	}
}
void show()
{
	temp=front;
		if(front==NULL && rear==NULL)
	cout<<"queue is empty\n";
	else
	{
    cout<<"queue elements are: ";
    while(temp!=NULL)
    {
    	cout<<temp->data<<endl;
    	temp=temp->next;
	}
	cout<<endl;
}
}
	void deleteelement()
	{
	 temp=front;
	 if(temp==NULL)
	 cout<<"underflow\n";
	 else
	 {
	 	temp=temp->next;
	 	cout<<"delted element is: "<<front->data<<endl;
	 	free(front);
	 	front=temp;
	 }
	}
int main()
{
	int n,x;
	cout<<"enter the number of values to be entered in the queue\n";
	cin>>n;
	cout<<"enter the values to be stored in the queue\n";
	for(int i=0;i<n;i++)
	{    cin>>x;
		insertelement(x);
	}
	show();
	return 0;
}
