#include<iostream>
#include<algorithm>
using namespace std;
struct jobs
{
	char job;
	int profit;
	int deadline;
};
bool compare(jobs a ,jobs b)
{
	return a.profit > b.profit;           //this function will sort in decreasing order of profit;
}
struct disjointset
{
	int * parent;  //dynamically aloocation of array
    disjointset(int n)
    {
    	parent=new int[n+1];
    	for(int i=0;i<=n;i++)
    	{
    		parent[i]=i;      //every node is parent of own node 
		}
	}
	void merge(int u,int v)
	{
		parent[v]=u;
	}
	int find(int node) 
    { 
        if (node == parent[node]) 
		{  
            return node;                                 //  Make the parent of the nodes in the path from u--> parent[u]
		}
        return parent[node] = find(parent[node]); 
    } 
    };
 int maxdeadline(jobs arr[], int n) 
{ 
    int res = INT_MIN; 
    for (int i = 0; i < n; i++) 
        res = max(res, arr[i].deadline); 
    return res; 
} 
 int jobschedulling(jobs arr[],int n)
    {
    	sort(arr, arr + n, compare); 
    	int maxDeadline = maxdeadline(arr, n); 
       disjointset ds(maxDeadline); 
       for (int i = 0; i < n; i++) 
        {
        int freeslot = ds.find(arr[i].deadline);
        if (freeslot > 0) 
        { 
            ds.merge(ds.find(freeslot - 1), freeslot); 
            cout << arr[i].job << " "; 
        } 
    } 
	}
int main()
{
		int n;
	cout<<"enter total number of jobs in a queue :";
	cin>>n;
	jobs arr[n];
	cout<<endl;
	cout<<" enter job number, job deadline, job profut:";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].job>>arr[i].deadline>>arr[i].profit;
	}
	cout<<"sequence of jobs to get maximum profit: ";
	jobschedulling(arr,n);
	return 0;
}
