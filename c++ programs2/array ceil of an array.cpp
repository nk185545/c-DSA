#include<iostream>
using namespace std;
int findCeil(int arr[],int n,int l,int h,int x)
{
	if(x <= arr[l])
	return l;
	if(x>=arr[h])
	return -1;
	int mid=(l+h)/2;
	if(arr[mid]==x)
	return mid;
	if(arr[mid] > x)
	{
		if(l<=mid-1 && x >= arr[mid-1])
		return mid;
		else
		return findCeil(arr,n,l,mid-1,x);
	}
	else
	{
		if(h>=mid+1 && x<=arr[mid+1])
		{
			return mid+1;
		}
	else
	 return findCeil(arr,n,mid+1,h,x);	
	}
}
int main()
{
	int arr[]={1, 2, 8, 10, 10, 12, 19};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=7;
   int index=findCeil(arr,n,0,n-1,x);
    cout<<arr[index];
}
