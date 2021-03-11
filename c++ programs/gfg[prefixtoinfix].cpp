#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
void prefixtoinfix(stack<string>&s,char ch[])
{
  int i=0;
  while(ch[i])
  {
	if(isalpha(ch[i]))
	{
			string str(1,ch[i]) ;
			s.push(str);
	}
   else if(ch[i]=='+' || ch[i]=='-' || ch[i]=='*'|| ch[i]=='/' || ch[i]=='^')
	{
		string a=s.top();
		s.pop();
		string b =s.top();
	    s.pop();
		s.push("("+a+ch[i]+b+")");
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
	int n=strlen(ch);
	reverse(ch,ch+n);
	prefixtoinfix(s,ch);
	cout<<s.top();
	return 0;
}
