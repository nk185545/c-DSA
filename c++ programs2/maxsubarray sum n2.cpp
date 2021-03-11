#include<iostream>
#include<vector>
using namespace std;
int maxSubarraySum(vector<int>arr,int n)
{
	int sum=0;
	int max_sum=INT_MIN;
	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=i;j<n;j++)
		{
			sum=sum+arr[j];
			max_sum=max(max_sum,sum);
		}
	}
	return max_sum;
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
	int ans=maxSubarraySum(arr,n);
	cout<<ans;
}
/*
9
-2
1
-3
4
-1
2
1
-5
4
*/
