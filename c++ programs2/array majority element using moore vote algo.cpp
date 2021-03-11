#include<iostream>
using namespace std;
int MajorityElement(int arr[],int n)
{
	int count=1,majority_index=0;
	for(int i=1;i<n;i++)
	{
		if(arr[majority_index]==arr[i])
		{
			count++;
		}
		else
		count--;
		if(count==0)
		{
			majority_index=i;
			count=1;
		}
	}
	return arr[majority_index];
}
bool majorityElement(int arr[],int n,int me)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	if(arr[i]==me)
	cnt++;
	if(cnt > n/2)
	return true;
	return false;
}
void printMajority(int arr[],int n)
{
	int cand=MajorityElement(arr,n);
	if(majorityElement(arr,n,cand))
	cout<<"majority element is: "<<cand;
	else
	{
		cout<<"no majority element";
	}
}
int main()
{
	int arr[]={3, 3, 4, 2, 4, 4, 2, 4, 4};
	int n=sizeof(arr)/sizeof(arr[0]);
	printMajority(arr,n);
}
