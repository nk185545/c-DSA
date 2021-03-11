#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int HistArea(vector<int>hist)
{
	stack<int>s;
	int hist_area;
	int max_area=0;
	int i=0;
	while(i<hist.size())
	{
		if(s.empty() || hist[s.top()] <=hist[i])
		{
			s.push(i);
			i++;
		}
		else
		{
		 	int tp=s.top();
			s.pop();
			hist_area=hist[tp]*(s.empty()?i:i-s.top()-1); 	
		}
		if(max_area<hist_area)
		max_area=hist_area;
	}
	while(!s.empty())
	{
		int tp=s.top();
		s.pop();
		hist_area=hist[tp]*(s.empty()?i:i-s.top()-1);
		if(max_area<hist_area)
		max_area=hist_area;
	}
	return max_area;
}
int main()
{
	int n;
	cout<<"enter n";
	cin>>n;
	vector<int>hist;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		hist.push_back(a);
	}
	int ans=HistArea(hist);
	cout<<ans;
}
