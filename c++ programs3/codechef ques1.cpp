#include<iostream>
#include<map>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
        for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		map<int,int>mp;
		for(int i=0;i<n;i++)
		{
			mp[arr[i]]++;
		}		
		int ans=mp.size();
		cout<<ans<<endl;	
	}
}
