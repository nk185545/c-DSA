#include<iostream>
using namespace std ;

int lps(string s)
{
	int n = s.length() ;
	int i=0 ;
	int ans = 0 ;
	while(i<n)
	{
		int j = i-1 ;
		int k = i+1 ;
		int len = 1 ;
		while(j>=0 && (k<n) && (s[j]==s[k]))
		{
			j-- ;
			k++ ;
			len +=2 ;
		}
		ans = max(ans,len) ;
		j=i-1 ;
		k = i ;
		len = 0 ;
		while(j>=0 && (k<n) && (s[j]==s[k]))
		{
			j-- ;
			k++ ;
			len +=2 ;
		}
		ans = max(ans,len) ;
		i++ ;
	}
	return ans ;
}

int main()
{
	string str ;
	cin>>str ;
	
	int x = lps(str) ;
	cout<<x ;
	return 0 ;	
}
