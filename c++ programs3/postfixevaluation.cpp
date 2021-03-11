#include<iostream>
#include<stack>
using namespace std;
int evaluatepostfix(string exp)
{
	stack<int>s;
	for(int i=0;i<exp.length();i++)
	{
		if(exp[i]>='0' && exp[i]<='9')
		s.push(exp[i]-'0');
		else
		{
			int v1=s.top();
			s.pop();
			int v2=s.top();
			s.pop();
			if(exp[i]=='+')
			s.push(v2+v1);
		    else if(exp[i]=='-')
					s.push(v2-v1);
		    else if(exp[i]=='*')
				     s.push(v2*v1);
			else if(exp[i]=='/')
				    s.push(v2/v1);
			else if(exp[i]=='%')
				    s.push(v2%v1);		
			}
		}
	return s.top();
}
int main()
{
	string str;
	cout<<"enter the string ";
	getline(cin,str);
	cout<<"postfix evaluatiion: "<<evaluatepostfix(str);
	return 0;
	
}
