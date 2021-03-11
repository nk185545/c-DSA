#include<iostream>
using namespace std;
void insert(int a2[],int a1[],int n,int m)
{
	int i=m-1;
	int j=0;
	while(j<n && i<m+n )
	{
		if(a1[i]<a2[j])
		{
			a1[i+1]=a2[j];
			i++;
			j++;
		}
		else if(a2[j] < a1[i])
		{
			a1[i+1]=a2[j];
			i++;
			int k=i;
		    while(a1[i]<a1[i-1] && i>0)
		    {
		    	swap(a1[i-1],a1[i]);
		    	i--;
			}
			i=k;
			j++;
		}
	}
}
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	int arr1[n];
	for(int i=0;i<n;i++)
	cin>>arr1[i];
	int arr2[m+n];
	for(int i=0;i<m;i++)
	{
		cin>>arr2[i];
	}
	insert(arr1,arr2,n,m);
	for(int i=0;i<m+n;i++)
	{
		cout<<arr2[i]<<" ";
	}
}
