#include<iostream>
#include<queue>
using namespace std;
void bfs(int x,int num)
{
	queue<int>q;

	q.push(num);
	while(!q.empty())
	{
		num=q.front();
		q.pop();
		if(num<=x)
		{
			cout<<num<<" ";
			 int last_digit=num%10;
		
			if(last_digit==0)
			{
				q.push((num*10)+(last_digit+1));
			}
			else if(last_digit==9)
			{
				q.push((num*10)+(last_digit-1));
			}
			else
			{
				q.push((num*10)+(last_digit-1));
				q.push((num*10)+(last_digit+1));
			}
		}
	}
}
void printJumpingNumber(int num)
{
	cout<<"0"<<" ";
	for(int i=1;i<=num && i<=9;i++)
	{
		
		bfs(num,i);
	}
}
int main()
{
	int num;
	cin>>num;
	printJumpingNumber(num);
}
