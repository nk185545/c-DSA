#include<iostream>
using namespace std;
void oddeven(int a[],int n)
{
	int i=0,j=1;
	while(j<n)
	{
		if(a[i]<0 && a[j]>0)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j++;
		}
	else if(a[i]<0 && a[j] <0)
		{
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}
}
int main()
{
	int n;
	cout<<"enter number of elements: ";
	cin>>n;
	int arr[n];
	cout<<"enter elements of an array :";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	oddeven(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
