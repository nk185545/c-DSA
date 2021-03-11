#include<iostream>
#include<vector>
using namespace std;
bool isSubsequence(string str,string s)
{
	int j=0;
	int i=0;
	while(j<str.length() && i< s.length())
	{
		if(str[j]==s[i])
		{
			j++;
			i++;
		}
		else
		{
			j++;
		}
	}
	return (i==s.length());
}
string largestLength(vector<string>&v,string str)
{
	int length=0;
	string result="";
	for(int i=0;i<v.size();i++)
	{
		string s=v[i];
		if(isSubsequence(str,s) && length<s.length())
		{
			length=s.length();
			result=s;
		}
	}
	return result;
}
int main()
{
	vector<string>v;
	cout<<"enter the number of strings: ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		v.push_back(str);
	}
	string s;
	cout<<"enter the string for checking: ";
	cin>>s;
	string ans=largestLength(v,s);
	cout<<ans;
}
/*
4
ape
apple
plae
monkey
abpcplea
*/
