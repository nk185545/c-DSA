#include<iostream>
#include<queue>
using namespace std;
void radixSort(vector<int>arr)
{
	queue<int>q[10];
	int x=1;
	while(q[0].size()!=arr.size())
	{
		for(int i=0;i<arr.size();i++)
		{
		  int a=(arr[i]/x)%10;
		  q[a].push(arr[i]);	
		}
		int j=0;
		int len=q[0].size();
		for(int i=0;i<10;i++)
		{
			while(!q[i].empty() && j<arr.size())
			{
				int ele=q[i].front();
				arr[j++]=ele;
			//	cout<<ele<<" ";
				q[i].pop();
			}
		}
		if(arr.size()==len)
		break;
		x=x*10;
	}
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	vector<int>v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	radixSort(v);
}
