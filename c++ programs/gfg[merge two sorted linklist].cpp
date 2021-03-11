#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
typedef struct node* lptr;
lptr create_linklist(lptr l,int x)
{
	lptr temp;
	lptr head=l;
    temp=new struct node();
	temp->data=x;
	temp->next=NULL;
	if(l==NULL)
	{
		return temp;
	}
	while(l->next != NULL)
	{
		l=l->next;
	}
	l->next=temp;
	return head;
}
lptr ll_merge(lptr root1,lptr root2)
{
	lptr result;
	if(root1==NULL)
	{
		return root2;
	}
	if(root2==NULL)
	{
		return root1;
	}
	if(root1->data <=root2->data)
	{
		result=root1;
	result->next=ll_merge(root1->next,root2);
	}
	else
	{
		result=root2;
		result->next=ll_merge(root1,root2->next);
	}
	return result;
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
	lptr root1=NULL,root3=NULL,root2=NULL;
	int x1,x2,n1,n2;
	cout<<"enter number of nodes in link list1 and 2 ";
	cin>>n1>>n2;
	cout<<"enter nodes of link list1 :\n";
	for(int i=0;i<n1;i++)
	{
		cin>>x1;
		root1=create_linklist(root1,x1);
	}
	cout<<"enter nodes of link list 2 :\n";
		for(int i=0;i<n2;i++)
	{
		cin>>x2;
		root2=create_linklist(root2,x2);
	}
	printlist(root1);
	cout<<endl;
	printlist(root2);
	cout<<endl;
	cout<<"link list after merging: ";
	root3=ll_merge(root1,root2);
	printlist(root3);
}
