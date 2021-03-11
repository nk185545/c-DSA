#include<iostream>
#include<map>
using namespace std;
void count(int arr[],int n)
{
	map<int,int> mp;
	int i=0;int j=0;
	int m=0;
	while(j<n)
	{
		if((mp.size()<2) || ((mp.size() <=2) && (mp.find(arr[j]) !=mp.end())))
		{
			mp[arr[j]]++;
			j++;
			
		}
		else
		{
			
			 m=max(m,j-i);
			 mp[arr[i]]--;
			 
			 if(mp[arr[i]]==0) mp.erase(arr[i]);
			 i++;
		}
			
	}	
	m=max(m,j-i);
	cout<<m;
}
int main()
{
	cout<<"enter number of elemetsn: ";
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	count(arr,n);
}
