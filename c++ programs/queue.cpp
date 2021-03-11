#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct queue
{
	stack<int>s1,s2;
	void enQueue(int x)
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	int dqueue()
	{
		if(s1.empty())
		{
			cout<<"q is empty ";
			exit(0);
		}
		int x=s1.top();
		s1.pop();
		return x;
	}
}
	int main()
	{
		queue q;
		q.enQueue(1);
		q.enQueue(2);
		q.enQueue(3);
		cout<<q.dequeue()<<'\n';
		cout<<q.dequeue()<<'\n';
		cout<<q.dequeue()<<'\n';
		return 0;
	}

