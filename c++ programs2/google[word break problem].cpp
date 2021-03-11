#include<iostream>
#include<vector>
using namespace std;
bool isDictContains(string str,vector<string>dict)
{
	for(int i=0;i<dict.size();i++)
	{
		if(dict[i]==str)
		{
			return true;
		}
	}
	return false;
}
bool wordBreak(vector<string>dict,string str)
{
	if(str.length()==0)
	return true;
	for(int i=1;i<=str.length();i++)
	{
		if(isDictContains(str.substr(0,i),dict) && wordBreak(dict,str.substr(i,str.length()-1)))
		{
			return true;
		}
		 
	}
	return false;
}
int main()
{
	vector<string>dict;
	cout<<"enter number of strings: ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		dict.push_back(str);
	}
	cout<<"enter string: ";
	string str;
	cin>>str;
	bool b=wordBreak(dict,str);
	cout<<b;
}
/*
12
i
like
sam
sung
samsung
mobile
ice
cream
icecream
man
go
mango
*/
