#include<iostream>
using namespace std;
void perculate_up(int a[50],int n,int key)
{
	a[n]=key;
	int j=n;
	while(a[j]<a[(j-1)/2] && j>0)
	{
		int temp;
		temp=a[(j-1)/2];
		a[(j-1)/2]=a[j];
		a[j]=temp;
		j=(j-1)/2;
	}
}
void perculate_down(int a[50],int &n)
{
	int value=a[0];
	a[0]=a[n-1];
	n=n-1;
	int j=0;
 while((a[j]>a[1+2*j]||a[j]>a[2+2*j])&&((1+2*j)<n ))
 {
 	if(a[j]>a[1+2*j]&&a[j]>a[2+2*j])
 	{
 		if(a[1+2*j]>a[2+2*j])
 		{
 			int temp=a[j];
 			a[j]=a[2+2*j];
 			a[2+2*j]=temp;
 			j=2+2*j;
		 }
		 else if(a[1+2*j]<a[2+2*j])
		 {
		 	int temp=a[j];
		 	a[j]=a[1+2*j];
		 	a[1+2*j]=temp;
		 	j=1+2*j;
		 }
	 }
	 else
	 {
	 	if(a[j]>a[1+2*j])
	 	{
	 		int temp=a[j];
	 		a[j]=a[1+2*j];
	 		a[1+2*j]=temp;
	 		j=1+2*j;
		 }
		 else if(a[j]>a[2+2*j])
		 {
	 		int temp=a[j];
	 		a[j]=a[2+2*j];
	 		a[2+2*j]=temp;
	 		j=2+2*j;
		 }
	 }
 }
 cout<<value<<" ";
}
int main()
{
	int n,key,a[50];
	cout<<"enter total number of elements in the array: ";
	cin>>n;
	
	cout<<"\n enter elements of tha array: ";// 10 12 15 20 40 25 18
	for(int i=0;i<n;i++)
	{
		cin>>key;
		perculate_up(a,i,key);
	}
	cout<<"minimumm heap is: ";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	int k=n;
	for(int i=0;i<k;i++)
	 perculate_down(a,n) ;
	return 0;
}
