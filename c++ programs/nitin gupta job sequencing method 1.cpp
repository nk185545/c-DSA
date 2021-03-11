#include<iostream>
#include<algorithm>
using namespace std;
struct jobschedulling
{
	int deadline;
	char job;
	int profit;
};
bool compare(jobschedulling a ,jobschedulling b)
{
	return a.profit > b.profit;           //this function will sort in decreasing order of profit;
}
void jobsequencing(jobschedulling arr[],int n)
{
	sort(arr,arr+n,compare);
	int res[n];     //resultant array
	int freeslot[n];
	for(int i=0;i<n;i++)
	{
		freeslot[i]=0;    // initially all slots are free
	}
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,arr[i].deadline)-1;j>=0;j--)
		{
			if(freeslot[j]==0)
			{
				res[j]=i;
				freeslot[j]=1;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(freeslot[i])
		cout<<arr[res[i]].job <<" ";
	}
}
int main()
{
	int n;
	cout<<"enter total number of jobs in a queue :";
	cin>>n;
	jobschedulling arr[n];
	cout<<endl;
	cout<<" enter job number, job deadline, job profut:";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].job>>arr[i].deadline>>arr[i].profit;
	}
	cout<<"sequence of jobs to get maximum profit: ";
	jobsequencing(arr,n);
	return 0;
}
/*
5
a 2 100
b 1 19
c 2 197
d 1 285
e 3 15
*/
