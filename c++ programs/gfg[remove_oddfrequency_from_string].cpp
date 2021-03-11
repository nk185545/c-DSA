#include<iostream>
#include<string.h>
#include<map>
using namespace std;
void remove_oddfrequency(string str)
{
	string rs="";
	map<char,int>mp;
	int s=str.length();
	for(int i=0;i<s;i++)
	{
		mp[str[i]]++;
	}
map<char,int>::iterator itr;
for(int j=0;j<s;j++)
{
	if(mp[str[j]]%2==0)
	{
		rs=rs+str[j];
	}
}
cout<<"after removing odd frequency characters : ";
int r=str.length();
for(int i=0;i<r;i++)
{
cout<<rs[i];
}
}
int main()
{
	string str;
	cout<<"enter the string  ";
	cin>>str;
	remove_oddfrequency(str);
}
