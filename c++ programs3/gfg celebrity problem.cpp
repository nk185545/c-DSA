#include<iostream>
#include<stack>
using namespace std;
void celebrity_problem(int arr[][4],int n,int m)
{
	stack<int>s;
	for(int i=0;i<n;i++)
	s.push(i+1);
	while(s.size()>1)
	{
		int a=s.top();
		s.pop();
		int b=s.top();
		s.pop();
		if(arr[a][b]==1)
		{
		s.push(b);	
		}
		else if(arr[a][b]==0)
		{
			s.push(a);
		}
    }
    int candidate=s.top();
    s.pop();
    for(int i=0;i<n;i++)
    {
    		if(i!=candidate)
    		{
    			if(arr[candidate][i]==1)
    			{
    				cout<<"no celebrity found ";
    				return;
				}
			}
	}
	cout<<"celebrity is: "<<candidate;
}
int main()
{
	int arr[][4]={ {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 1, 0, 0},
           {0, 0, 1, 0} };
    int n=4,m=4;
	celebrity_problem(arr,n,m);       
}
