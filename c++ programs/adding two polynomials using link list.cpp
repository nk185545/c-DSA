#include<iostream>
using namespace std;
struct node
{
	int coefficient;
	int power;
	struct node*next;
};
typedef struct node*lptr;
lptr createnode(int x,int y)
{   lptr dum;
	lptr temp=new node();
	if(temp==NULL)
	cout<<"cannot be allocated";
	temp->coefficient=x;
	temp->power=y;
	temp->next=NULL;
    dum->next=temp;
    dum=temp;
    return(dum);
	}
void printlist(lptr l)
{
	while(l!=NULL)
	{
		cout<<l->coefficient<<"x^"<<l->power<<" ";
		l=l->next;
	}
}
lptr addpolynomial(lptr poly1,lptr poly2)
{
	lptr poly3=NULL;
	lptr p,q;
	p=poly1;
	q=poly2;
	while(p!=NULL &&q!=NULL)
	{
		 if(p->power==q->power)
		 {
		 	  
		 	lptr l;
		 	poly3->coefficient=p->coefficient+q->coefficient;
		 	poly3->power=p->power;
		 	p=p->next;
		 	q=q->next;
		 	l=createnode(poly3->coefficient,poly3->power);
		 }
		 else
		 {
		 	if(p->power>q->power)
		 	{
		 		lptr l;
		 		poly3->coefficient=p->coefficient;
		 	    poly3->power=p->power;
		 	    p=p->next;
		 	    l=createnode(poly3->coefficient,poly3->power);
			 }
			 else
			 {
			 	lptr l;
			 	lptr temp=new node();
			 	poly3->coefficient=q->coefficient;
		 	    poly3->power=q->power;
		 	    q=q->next;
		 	    l=createnode(poly3->coefficient,poly3->power);
			 }
		 }
	}
	while(p!=NULL)
	{
		lptr l;
			lptr temp=new node();
			poly3->coefficient=p->coefficient+q->coefficient;
		 	poly3->power=p->power;
		 	p=p->next;
		 	l=createnode(poly3->coefficient,poly3->power);
	}
	while(q!=NULL)
	{
		lptr l;
			lptr temp=new node();
			poly3->coefficient=p->coefficient+q->coefficient;
		 	poly3->power=q->power;
		 	q=q->next;
		 	l=createnode(poly3->coefficient,poly3->power);
	}
	return poly3;
}
int main()
{
	lptr l1=NULL;
	lptr l2=NULL;
	int x1,y1,x2,y2,n,m;
	lptr start=NULL;
	cout<<"enter the number of nodes in polynomial 1 \n";
	cin>>n;
	cout<<"enter the coefficient and power of polynomial 1:  ";
	for(int i=0;i<n;i++)
	{
	cin>>x1>>y1;
	l1=createnode(x1,y1);
}
printlist(l1);
cout<<"enter the number of nodes in polynomial 2 \n";
	cin>>m;
	cout<<"enter the coefficient and power of polynomial 2:  ";
	for(int i=0;i<m;i++)
	{
	cin>>x2>>y2;
	l2=createnode(x2,y2);
}
printlist(l2);
start=addpolynomial(l1,l2);
cout<<"addition of two polynomials is: ";
 printlist(start);
return 0;
}
