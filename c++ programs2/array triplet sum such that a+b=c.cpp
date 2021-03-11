#include<iostream>
using namespace std;
void triplet(int arr[],int n)
{
	for(int k=n-1;k>=0;k--)
     {
  	int i=0;
  	int j=k-1;
	while(i<j)
	{
		if(arr[i]+arr[j]==arr[k])
		{
			cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
			i++;
			j--;
		}
		else
		if(arr[i]+arr[j]>arr[k])
		{
			j--;
		}
		else
		{
			i++;
		}
	}
}
}
int main()
{
	int arr[]={1,2,3,5,7,8};
	int n=6;
	triplet(arr,n);
	return 0;
}
