#include<iostream>
using namespace std;
bool metaStrings(string s1,string s2)
{
    int length1=s1.length();
    int length2=s2.length();
    int swap=0;
    if(length1!=length2)
    return false;
    for(int i=0;i<length1;i++)
    {
    	if(s1[i]!=s2[i])
    	{
    		swap++;
		}
	}
    if(swap==2)
	{
		return true;
	}
	else
	{
		return false;
	}	
}
int main()
{
	string s1,s2;
	cout<<"enter the string one:";
	cin>>s1;
	cout<<"enter string 2: ";
	cin>>s2;
	bool ans=metaStrings(s1,s2);
	cout<<ans;
}
