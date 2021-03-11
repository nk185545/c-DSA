#include <iostream>
using namespace std;
bool fun(int arr[],int n,int k)
{
    int i=0;
    int j=n-1;
    int sum=0;
    while(i<j)
    {
       sum=arr[i]+arr[j];
        if(k==sum)
    {
    cout<<arr[i]<<" "<<arr[j];
    return true;
    }
       if(sum<k)
       {
           i++;
       }
       else
       {
       j--;
       }
}
    	return false;
}
int main() {
	cout<<"GfG!";
	int k,n;
	bool b=false;
	int arr[n];
	cin>>k;
	cin>>n;
	for(int i=0;i<n;i++) 
	{
	    cin>>arr[i];
	}
	b=fun(arr,n,k);
	return 0;
}
