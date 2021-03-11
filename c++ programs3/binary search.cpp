#include<iostream>
using namespace std;
int binary(int l,int h,int item,int n,int a[])
{
	int mid=(l+h)/2;
	while(l<=h)
	{
		if(item==a[mid])
		return mid;
	   else	if(item>a[mid])
	 return binary(mid+1,n-1,item,n,a);
		else 
		return binary(0,mid-1,item,n,a);
	}
}
int main()
{
	int item,*a=NULL,n,loc=-1,k,data;
	cout<<"enter the number of elements in an array\n";
	cin>>n;
	a=new int[n+1];
	cout<<"enter elements of the array\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<"enter the element which you want to search\n";
	cin>>item;
	loc=binary(0,n-1,item,n,a);
	if(loc!=-1)
	{
	cout<<"item is found at location "<<loc<<endl;
	cout<<"deleted element is  "<<a[loc]<<" at location "<<loc<<endl;
}
	else
	{
	cout<<"item is not present\n";
	cout<<"enter the position at which you want to insert the element "<<endl;
	cin>>k;
	cout<<"enter the element which you want to insert in the array at given position "<<endl;
	cin>>data;
	for(int i=n;i<=n-k;i++)
	a[i+1]=a[i];
	a[k-1]=a[k];
	cout<<"new array is:"<<endl;
	for(int i=0;i<n+1;i++)
	cout<<a[i];
}
	return 0;
}
