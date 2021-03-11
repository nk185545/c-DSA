#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selection_sort(int a[],int n)
{
	int i,j,min,temp;
	for(i=0;i<=n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			min=j;
		}
   swap(&a[min],&a[i]);
   cout<<a[i]<<"  ";
	}
}
int main()
{
	int*a=NULL,n;
	a=new int[n];
	cout<<"enter the number of elements of an array"<<endl;
	cin>>n;
	cout<<"enter the elements of an array"<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<"array after sorting: "<<" ";
	selection_sort(a,n);
	return 0;
}
