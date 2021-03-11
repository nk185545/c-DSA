#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
void postfixtoinfix(stack<string>&s,char ch[])
{
  int i=0;
  while(ch[i])
  {
	if(isalpha(ch[i]))
	{
		{
			string str(1,ch[i]) ;
			s.push(str);
		}
	}
	string a,b;
   else(ch[i]=='+' || ch[i]=='-' || ch[i]=='*'|| ch[i]=='/' || ch[i]=='^')
	{
		 a=s.top();
		s.pop();
		 b =s.top();
		s.pop();
		s.push("("+b+ch[i]+a+")");
	}
	i++;
}
}
int main()
{
		stack<string>s;
	char ch[100];
	cout<<"enter the string ";
	cin.getline(ch,100);
	postfixtoinfix(s,ch);
	cout<<s.top();
	return 0;
}
