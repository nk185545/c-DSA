#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int>s1,s2;
	int a[20];
	int i,j,n;
	cout<<"enter the number of elements in the array ";
	cin>>n;
	cout<<"\n enter the elements of an array\n ";
	for(i=0;i<n;i++)
	cin>>a[i];
	s1.push(a[0]);
	for(i=1;i<n;i++)
	{
		if(a[i]<s1.top())
		s1.push(a[i]);
		else
		{
			while(!s1.empty()&&a[i]>s1.top())
			{
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(a[i]);
			while(!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
	}
	while(!s1.empty())
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}
	return 0;
}

