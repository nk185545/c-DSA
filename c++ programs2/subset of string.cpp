#include<iostream>
using namespace std;
void printSubset(string str)
{
	if(str.size()==0)
	cout<<str;
	for(int i=0;i<str.size();i++)
	{
		for(int j=i;j<str.size();j++)
		{
			printSubset(str.substr(i,j));
		}
    }
}
int main()
{
	string str;
	cout<<"enter string : ";
	cin>>str;
	printSubset(str);
}
