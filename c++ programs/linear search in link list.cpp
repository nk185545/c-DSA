#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
typedef struct node *lptr ;
lptr createlist(lptr L , int x)
{
	lptr t = L ;
	lptr temp = new node() ;
	temp->data = x ;
	temp->next = NULL ;
	
	if(t==NULL)
	{
		L=temp ;
	}
	else
	{
		while(t->next !=NULL)
		{
			t=t->next ;
		}
		t->next = temp ;
	}
	return L ;
}
void printlist( lptr L )
{   while(L!=NULL)
	{
		cout<<L->data<<" ";
		L=L->next ;
	}
}
int search(int item)
{
	int count=1;
	lptr l,t;
	t=l;
	while(t->next!=NULL)

	{
		if(t->data==item)
			break;
		else
			count++;
			t=t->next;
	}

	return count;

}

int main()
{
	lptr L = NULL ;
	cout<<"Enter number of elements : "<<endl;
	int n,item,result;
	cin>>n;
	cout<<"Enter the elements of linked list : "<<endl;
	for(int i=0 ; i<n ; i++)
	{
		int x ;
		cin>>x ;
		L=createlist(L,x) ;
	}
	
	printlist(L);
	cout<<"enter item to be searched";
	cin>>item;
	result=search(item);
	if(result<=n)
		cout<<"item is present in link list at index "<<n;
		else
		cout<<"item is not present in link list";
}
