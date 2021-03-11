#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *last;
void create_node(int value)
{
    node *temp;
    temp = new node;
    temp->data = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;   
    }
    else
    {
        temp->next = last->next; 
        last->next = temp;
        last = temp;
    }
}
void Print()
{
    node *s;
    if (last == NULL)
      return;      
    s = last->next;
    while (s != last)
    {
        cout<<s->data<<" -> ";
        s = s->next;
    }
    cout << s->data << endl;
}
int main()
{
	create_node(5);
	Print();    
	create_node(3);
	Print();     
	create_node(9);
	Print();
	return 0;
}

