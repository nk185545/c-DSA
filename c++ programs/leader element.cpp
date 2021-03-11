#include<iostream>
using namespace std;
void leaderelement(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{int j;
	for(j=i+1;j<size;j++)
	{
		if(arr[i]<=arr[j])
		break;
	}
	if(j==size)
	cout<<arr[i]<<" ";}
}
int main()
{
int arr[]={16,15,8,9,45,67,3,2};
int size=sizeof(arr)/sizeof(arr[0]);
leaderelement(arr,size);
return 0;	
}
