#include<iostream>
#include<stack>
using namespace std;
int getindex(char c)
{
	if(c=='+')
	return 1;
	if(c=='-')
	return 1;
	if(c=='*')
	return 2;
	if(c=='/')
	return 3;
	if(c=='%')
	return 4;
	if(c=='^')
	return 5;
}
void infixtopostfix(stack<char>s,char ch[])
{
	int i=0;
	while(ch[i])
 { 
    if(isdigit(ch[i]))
	cout<<ch[i];
	if(ch[i]=='+' || ch[i]=='-' || ch[i]=='*' || ch[i]=='/' || ch[i]=='%'||ch[i]=='^')
	{
		if(s.size()==0)
		{
			s.push(ch[i]);
		}
		else if(getindex(ch[i]>getindex(s.top())))
			{
				s.push(ch[i]);
			}
			else
			{
				while(s.size()!=0 && getindex(ch[i])<=getindex(s.top()))
				{
				cout<<s.top();
				s.pop();
			}
			s.push(ch[i]);
		}
	}

	i++;
}
while(!(s.empty()))
{
	cout<<s.top();
	s.pop();
}
}
int main()
{
	stack<char>s;
	char ch[100];
	cout<<"enter the string ";
	cin.getline(ch,100);
	infixtopostfix(s,ch);
	return 0;
	return 0;
}
