#include<iostream>
using namespace std;
void findCeil(int arr[],int n,int x)
{
	int c_index,f_index;
	int c_dist=INT_MAX,f_dist=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=x && c_dist>(arr[i]-x))
		{
			c_index=i;
			c_dist=arr[i]-x;
		}
		if(arr[i]<=x && c_dist>(x-arr[i]))
		{
			f_index=i;
			f_dist=x-arr[i];
		}
		
	}
	if(c_dist==INT_MAX)
	{
		cout<<"ceil doesnt exist in array";
	}
	else
	{
		cout<<"ceil is: "<<arr[c_index];
	}
	if(f_dist==INT_MAX)
	{
		cout<<"floor doesnt exist in array";
	}
	else
	{
		cout<<"floor is: "<<arr[f_index];
	}	
}
int main()
{
	int arr[]={5, 6, 8, 9, 6, 5, 5, 6};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=7;
   findCeil(arr,n,x);
}
