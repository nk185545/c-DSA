#include<iostream>
#include<stack>
using namespace std;
void nextgreater(int arr[],int ans[],int n)
{
	stack<int>s;
	s.push(arr[n-1]);
	ans[n-1]=-1;
	for(int i=n-2;n>=0;i--)
	{
		if(arr[i]<s.top())
		{
			ans[i]=s.top();
			s.push(arr[i]);
		}
	else
	{
		while(s.size() > 0 && s.top() < arr[i])
		{
			s.pop();
		}
		if(s.size()==0)
		{
			ans[i]=-1;
			s.push(arr[i]);
		}
		else
		{
		ans[i]=s.top();
		s.push(arr[i]);
		}	
	}
}
}
int main()
{
	int n;
	cout<<"enter number of elements: ";
	cin>>n;
	int arr[n];
	int ans[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	 nextgreater(arr,ans,n);
	 for(int i=0;i<n;i++)
	 {
	 	cout<<ans[i]<<" ";
	 }
	 
}
