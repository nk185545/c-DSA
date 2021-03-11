#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
typedef struct node* lptr;
lptr create_list(lptr L,int x)
{
	lptr head=NULL,temp=NULL;
	head=L;
	temp=new struct node();
	temp->data=x;
	temp->next=NULL;
	if(L==NULL)
	{
		return temp;
	}
	while(L->next!=NULL)
	{
		L=L->next;
	}
	L->next=temp;
	return head;
}
void printlist(lptr L)
{
	while(L!=NULL)
	{
		cout<<L->data<<" ";
		L=L->next;
	}
}
lptr remove_duplicates(lptr L)
{
   lptr temp=NULL;
   lptr head=NULL;
   head=L;
   temp=L;
   if(L==NULL || L->next==NULL)
   {
   	return L;
   }
   while(temp->next!=NULL)
   {
   	if(temp->data == temp->next->data)
   	{
   		head->next=temp->next->next;
   		temp->next=head->next;  
     }
     else
     {
     	temp=temp->next;
     	head=head->next;
	 }
   }
   return L;
  	
}
int main()
{
	lptr root=NULL;
	int x,n;
	cout<<"enter total no of nodes: \n";
	cin>>n;
	cout<<"enter nodes:   ";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		root=create_list(root,x);
	  }  
	  printlist(root);
	  cout<<endl;
	  remove_duplicates(root);
	  printlist(root);
}
