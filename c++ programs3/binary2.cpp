#include<iostream>
using namespace std;
int binary(int l,int h,int item,int a[20])
{
	int n;
	int mid=(l+h)/2;
	if(l<=h)
	{
		if(item==a[mid])
		{
		return mid+1;
	      }
	   else	if(item>a[mid])
	return	binary(mid+1,h,item,a);
		else
		return binary(l,mid-1,item,a);
	}
	return -1;
}
int main()
{
	int item,a[20],n,loc,k,data;
	cout<<"enter the number of elements in an array\n";
	cin>>n;
	cout<<"enter elements of the array\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<"enter the element which you want to search\n";
	cin>>item;
	loc=binary(0,n-1,item,a);
	if(loc!=-1)
	{
	cout<<"item is found at location "<<loc<<endl;
	cout<<"deleted element is  "<<a[loc-1]<<" at location "<<loc<<endl;
	cout<<"new array after deletion the element is:\n";
	for(int i=loc-1;i<n-1;i++)
	a[i]=a[i+1];
	for(int i=0;i<n-1;i++)
	cout<<a[i]<<endl;
}
	else
	{
	cout<<"item is not present\n";
	cout<<"enter the position at which you want to insert the element "<<endl;
	cin>>k;
	cout<<"enter the element which you want to insert in the array at given position "<<endl;
	cin>>data;
	for(int i=n-1;i>=n-k;i--)
	a[i+1]=a[i];
	a[k-1]=data;
	cout<<"new array is:"<<endl;
	for(int i=0;i<=n;i++)
	cout<<a[i]<<endl;
}
return 0;
}

