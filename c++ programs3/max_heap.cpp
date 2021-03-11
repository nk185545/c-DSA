#include<iostream>
using namespace std;
int max_heapify(int a[20],int i,int n)
{
	int largest=i,l,r;
	l=2*i+1;
	r=2*i+2;
	if(l<n && a[l]>a[i])
	largest=l;
	if(r<n && a[r]>a[largest])
	largest=r;
	if(largest!=i)
	{
	int temp=a[i];
	a[i]=a[largest];
	a[largest]=temp;
	max_heapify(a,largest,n);	 
}
}
int heap(int a[20],int n)
{
	int s=(n/2)-1;
	for(int i=s;i>=0;i--)
	max_heapify(a,i,n);
}
int main()
{
	int n,a[20];
	cout<<"enter total number of elements: ";
	cin>>n;
	cout<<"\nenter elements of an array: ";//7  10 20 15 12 40 25 18 
	for(int i=0;i<n;i++)
	cin>>a[i];
	heap(a,n);
	cout<<"\n maximum heap is: ";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
