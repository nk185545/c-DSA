#include<iostream>
#include<algorithm>
using namespace std;
int main()
{  int t;
	cin>>t;
	while(t)
	{   int a,b,c,d;
		cin>>a>>b>>c>>d;
		int ans=max(a+b,c+d);
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
