#include<iostream>
#include<vector>
using namespace std;
int maxWaterContainer(vector<int>v)
{
	int area=0;
	int i=0;int j=v.size()-1;
	while(i<j)
	{
		area=max(area,min(v[i],v[j])*(j-i));
		if(v[i]<v[j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return area;
}
int main()
{
	vector<int>v;
	int n;
	cout<<"enter no. of elements: ";
	cin>>n;
	for(int i=0;i<n;i++)
    {
    	int a;
    	cin>>a;
    	v.push_back(a);
	}
	int ans=maxWaterContainer(v);
	cout<<ans;
}
