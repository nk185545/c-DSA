#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;
int main()
{
	string str; 
	bool pal=true;
	queue<char>q;
	stack<char>s;
	cout<<"enter a string to check whethere string is palindrome or not: ";
	getline(cin,str);
	int l;
	l=str.size();
	for(int i=0;i<l/2;i++)
	{
		s.push(str[i]);
	}
	if((l%2)!=0)
	{
		for(int i=((l/2)+1);i<l;i++)
		q.push(str[i]);
	}
	else
	{
	for(int i=l/2;i<l;i++)
	q.push(str[i]);
}
	while(!q.empty() && !s.empty()&&pal)
	{
		if(q.front()!=s.top())
		
		{
			pal=false;
		}
		else
		{
			q.pop();
			s.pop();
		}
		
	}
	if(pal)
	cout<<"string is palindrome ";
	else
	cout<<"string is not palindrome";
	return 0;
}
