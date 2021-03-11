#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>v,int n,int d)
{
	vector<int>temp;
	for(int i=0;i<d;i++)
	{
		temp.push_back(v[i]);
	}
	int i=0;
	for( i=0;i<n-d;i++)
	{
		v[i]=v[i+d];
	}
	for(int j=0;j<d;j++)
	{
		v[i++]=temp[j];
	}
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
}
int main()
{
	vector<int>arr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}
	int d;
	cin>>d;
	rotate(arr,n,d);
}
