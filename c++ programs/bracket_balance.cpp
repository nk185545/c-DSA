#include<iostream>
#include<stack>
using namespace std;
void bracket_balance(stack<char>s,char ch[])
 {
 	
	int i=0;
	while(ch[i])
 { 
    if(isdigit(ch[i]))
	cout<<ch[i];
	if(ch[i]=='+' || ch[i]=='-' || ch[i]=='*' || ch[i]=='/' || ch[i]=='%'||ch[i]=='^')
	{
		cout<<ch[i];
 }
 if(ch[i]=='(')
 {
 s.push(ch[i]);
}
 else if(ch[i]==')')
 {
 	while(s.size()!=0 && ch[i]==')')
 	{
 		s.pop();
	 }
 }
 else
 {
 	s.push(ch[i]);
 }
 i++;
}
if(s.empty())
cout<<"balanced";
else
cout<<"not balanced";
}
int main()
{
	stack<char>s;
	char ch[100];
	cout<<"enter the string ";
	cin.getline(ch,100);
	bracket_balance(s,ch);
	return 0;
}
