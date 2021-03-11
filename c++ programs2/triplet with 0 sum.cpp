#include<iostream>
#include<algorithm>
using namespace std;
void triplet(int arr[],int n)
{
	sort(arr,arr+n);
	for(int k=n-1;k>=0;k--)
     {
  	int i=0;
  	int j=k-1;
	while(i<j)
	{
		if(arr[i]+arr[j]+arr[k]==0)
		{
			cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
			i++;
			j--;
		}
		else
		if(arr[i]+arr[j]+arr[k]>0)
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
	int arr[]={0, -1, 2, -3, 1};
	int n=6;
	triplet(arr,n);
	return 0;
}
