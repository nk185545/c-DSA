#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node*next;
};
typedef struct node* lptr;
class circularlinklist
{
	public:
		void traverslist(lptr last)
		{
			lptr p;
			if(last==NULL)
			{
				cout<<"circular link list is empty. "<<endl;
				return;
			}
			p=last->next;
			while(p!=last->next)
			{
				cout<<p->data<<"==>";
				p=p->next;
			}
			if(p==last->next)
             {
             	cout<<p->data<<endl;
			 }
		}
		lptr insertnode(lptr last,int new_data)
		{
			if(last!=NULL)
			{
				return last;
			}
			lptr temp=new node();
			temp->data=new_data;
			last=temp;
			last->next=last;
			return last;
		}
			void enterelements()
	{
	lptr last=NULL;
	cout<<"enter number of nodes of link list:"<<endl;
	int n;
	cin>>n;
    cout<<"enter the elements of linked list: "<<endl;
	for(int i=0;i<n;i++)
	{
		int new_data;
		cin>>new_data;
		last=insertnode(last,new_data);
		}	
		traverslist(last);
	}
};
    int main()
	{
		circularlinklist c;
		c.enterelements();
		
	   return 0;
          }
