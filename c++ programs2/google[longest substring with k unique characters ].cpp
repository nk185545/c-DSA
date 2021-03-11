#include<iostream>
#include<map>
using namespace std;
bool notValid(int count[26],string str,int k)
{
	int cnt=0;
	for(int i=0;i<26;i++)
	{
		if(count[i]>0)
		{
			cnt++;
		}
	}
	return (cnt<=k);
}
void uniqueChar(string str,int k)
{
	int count[26] ={0} ;
	int cnt=0;
	for(int i=0;i<26;i++)
	{
		if(count[str[i]-'a' ]==0)
		{
			cnt++;
		}
		count[str[i]-'a']++;
	}
	if(cnt<k)
	{
		cout<<"no such substring exist ";
	}
	if(cnt==k)
	{
		cout<<str;
	}
	int max_win_len=1;
	int win_len=0;
	int i=0;
	int j=0;
	for(int s=0;s<26;s++)
	{
		count[s]=0;
	}
	count[str[0]-'a']++;
	int max_win_start=0;
	for(int l=1;l<str.length();l++)
	{
		count[str[l]-'a']++;
		j++;
		while(!notValid(count,str,k))
		{
			count[str[i]-'a']--;
			i++;
		}
		if(max_win_len <j-i+1)
		{
			max_win_len=j-i+1;
			max_win_start=i;
		}
	}
	cout<<"max window start from "<<str.substr(max_win_start,max_win_len)<<" with length "<<max_win_len;
}
int main()
{
	cout<<"enter the string: ";
	string str;
	cin>>str;
	cout<<"enter k ";
	int k;
	cin>>k;
	uniqueChar(str,k);
}
