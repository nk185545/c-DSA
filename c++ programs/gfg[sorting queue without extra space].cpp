#include<iostream>
#include<queue>
using namespace std;
int getminindex(queue<int>&q,int a)
{
	int min_value=INT_MAX;  // mi=min index
	int min_index=-1;
	int i;
	int n=q.size();
	for(i=0;i<n;i++)
	{
		int fnt=q.front();
		q.pop();
		if(fnt<=min_value && i<=a)
		{
			min_index=i;
			min_value=fnt;
		}
		q.push(fnt);
	}
	return min_index;
}
void insertmintorear(queue<int>&q,int minindex)
{
	int n=q.size();
	int minvalue;
	for(int i=0;i<n;i++)
	{
		int ans=q.front();
		q.pop();
		if(i!=minindex)
		{
			
			q.push(ans);
		}
		else
		{
			 minvalue=ans;
		}
	}
	q.push(minvalue);
}
void sortqueue(queue<int>&q,int n)
{
	for(int i=0;i<=n;i++)
	{
	int minindex=getminindex(q,n-i);
	insertmintorear(q,minindex);
}
}
int main()
{
	queue<int>q;
	int n;
	q.push(11);
	q.push(5);
	q.push(4);
	q.push(21);
	n=q.size();
	sortqueue(q,n-1);
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	
}
