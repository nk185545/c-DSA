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
	if(str.size()==0)
	return true;
	int n=str.size();
	bool bl[n+1];
	for(int i=0;i<=n;i++)
	{
		bl[i]=false;
	}
	for(int i=1;i<=str.length();i++)
	{
		if(bl[i]==false && isDictContains(str.substr(0,i),dict)) 
		{
			bl[i]=true;
		}
		if(bl[i]==true)
		{
			if(str.length()==0)
			 return true;
			 for(int j=i+1;j<=str.size();j++)
			 {
			 	if(bl[j]==false && isDictContains(str.substr(i,j-1),dict))
			 	{
			 		bl[j]=true;
				 }
				 if(j==str.size() && bl[j]==true)
				 {
				 	return true;
				 }
			 }
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

