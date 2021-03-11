#include<iostream>
using namespace std;
int a[100],n,front =-1,rear=-1;
void insert()
{int value;
	if(rear==n-1)
	cout<<"queue is full(overflow)\n";
	else
	{
		if(front==-1)
		front=0;
		cin>>value;
		rear++;
		a[rear]=value;
	}
}
void deleteelement()
{
	int value;
	if(front==-1||front>rear)
	{
	cout<<"queue underflow\n";
	return ;
}
else
{
	cout<<"deleted element from queue is: "<<a[front]<<endl;
	front++;
}
}
void display()
{
	if(front==-1)
	cout<<"queue is empty\n";
	else
	{
    cout<<"queue elements are: ";
	for(int i=front;i<=rear;i++)
	{
	cout<<a[i];
	cout<<endl;
}
}
}
int main()
{
cout<<"enter total number of elements in the queue\n";
cin>>n;
cout<<"insert the elements in the queue\n";
for(int i=0;i<n;i++)
insert();
display();
return 0;		
}
