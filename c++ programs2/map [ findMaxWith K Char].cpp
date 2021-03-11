#include<iostream>
#include<map> 
using namespace std ;

void findMaxwithKchar(int a[], int n, int k)
{
	if(k>n) cout<<"ans is : "<<0<<endl ;
	
	int i=0;
	int j=0 ;
	map<int,int> mp ;
	int ans=0 ;
	while(j<n)
	{
		if(mp.size() <k || (mp.size() ==k && mp.find(a[j])!=mp.end()))
		{
			mp[a[j]]++ ;
		}
		else
		{
			ans = max(ans,j-i) ;
			mp[a[i]] -- ;
			if(mp[a[i]]==0)
			{
				mp.erase(a[i]) ;
			}
			mp[a[j]]++;
			i++ ;
			
		}
		j++ ;
	}
	ans = max(ans,j-i) ;
	cout<<ans<<endl;
}

int main()
{
	int a[100] = {5,2,1,2,3,2,4,5,6,8,2,3} ;
	int n = 12 ;
	int k=3 ;
	findMaxwithKchar(a,n,k) ;
	return 0 ;
}
