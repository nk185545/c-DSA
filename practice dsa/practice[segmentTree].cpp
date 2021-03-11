#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void createSegmentTree(vector<int>arr,vector<int>&segment,int low,int high,int index)
{
	if(low==high)
	{
		segment[index]=arr[low];
		return;
	}
	int mid=(low+high)/2;
	createSegmentTree(arr,segment,low,mid,2*index+1);
	createSegmentTree(arr,segment,mid+1,high,2*index+2);
	segment[index]=min(segment[2*index+1],segment[2*index+2]);
}
int rangeQuery(vector<int>segment,int queryLow,int queryHigh,int low,int high,int index)
{
	if(queryLow <=low && queryHigh>=high)
	{
		return segment[index];
	}
	if(queryLow >high || queryHigh <low)
	{
		return INT_MAX;
	}
	int mid=(low+high)/2;
	return min(rangeQuery(segment,queryLow,queryHigh,low,mid,2*index+1),rangeQuery(segment,queryLow,queryHigh,mid+1,high,2*index+2));
}
int main()
{
	vector<int>v;
	cout<<"enter number of elements: ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	int n1;
	float x=(log2(n));
	int y=(int)x;
	if(x==y)
	{
		n1=2*n-1;
	}
	else
	{
		n1=pow(2,y+1)*2-1;
	}

	int z=(n1+1)/2;
	for(int i=n;i<z;i++)
	{
		v.push_back(INT_MAX);
	}
	vector<int>segment(n1,0);
	createSegmentTree(v,segment,0,z-1,0);
	for(int i=0;i<n1;i++)
	{
		cout<<segment[i]<<" ";
	}
	cout<<endl;
	int queryAns=rangeQuery(segment,4,5,0,z-1,0);
	cout<<queryAns;
}
/*
6
-1
2
4
0
5
9
*/
