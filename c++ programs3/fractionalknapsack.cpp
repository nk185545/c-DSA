#include<iostream>
#include<algorithm>
using namespace std;
struct knapsack
{
	float val;
	float weight;	
};
bool compare(knapsack a,knapsack b)
{
	return (a.val/a.weight) > (b.val/b.weight);
}
int main()
{
	float c;
	cout<<"enter capacity: ";
	cin>>c;
	int n;
	cin>>n;
	struct knapsack ks[n];
	cout<<"enter val and weight:  ";
	for(int i=0;i<n;i++)
	{
		cin>>ks[i].val>>ks[i].weight;
	}
	sort(ks,ks+n,compare);
	int i=0;
	float ans=0;
	while(i<n && c>0)
	{
	if(ks[i].weight > c)
	{
	break;
	}	
		else
		{
		ans=ans+ks[i].val;	
		c=c-ks[i].weight;
		i++;
	}
}
if(c!=0)
{
	ans=ans+(c*(ks[i].val))/ks[i].weight;
}
cout<<ans<<endl;
return 0;
}
