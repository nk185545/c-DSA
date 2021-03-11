#include<iostream>
#include<stack.h>
using namespace std;
stack<int>s1;
stack<int>s2;
int dequeue(int data)
{
	int a;
 if(s2.isempty())
 {
 	if(s1.isempty())
 	cout<<"queue is empty so we cannot delete any element "<<endl;
 	while(!s1.isempty())
 	{
 		a=s1.pop();
 		s2.push(a);
	 }
	 return s2.pop();
	 }	
	
}
void enqueue(int data)
{
  s1.push(data);
}
int main()
{
	int data,n;
	cout<<"enter number of elements in the queue"<<endl;
	cin>>n;
	cout<<"enter elements of the queue"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		enqueue(data);
	}
	dequeue(data);
	return 0;
}
//sun na yaar 
//love u ashwini
