#include<iostream>
using namespace std;
int binarysearch(int arr[],int low,int high,int key)
{
	
	if(low>high)
	return -1;
	int mid=(low+high)/2;
	if(arr[mid]==key)
	return mid;
	if(key>arr[mid])
	return binarysearch(arr,(mid+1),high,key);
	else
	return binarysearch(arr,low,(mid-1),key);
}
int main()
{
	int arr[]={3,6,7,8,9,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=10;
	cout<<"index of the element is:"<<binarysearch(arr,0,n-1,key);
	return 0; 
}
