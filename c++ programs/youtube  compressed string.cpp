#include<iostream>
using namespace std;
string to_string(int num)
{
	string s = "" ;
	while(num>0)
	{
		int x = num%10 ;
		num = num/10 ;
		s =  char(x+'0') + s ;
	}
	return s ;
}
void compressString(string a[],int n)
{
	int j=0;
	int i=0;
	int cnt=0;
	int index=0;
	a[index++]=a[0];
	while(j<n)
	{
	if(a[i]==a[j])
	{
		j++;
		cnt++;
	}
	else
	{
		if(cnt>1)
		a[index++]=to_string(cnt);
		a[index++]=a[j];
		cnt=0;
	    i=j;
	}
}
if(cnt>1)
{
	a[index]=to_string(cnt);
}
for(int k=0;k<=index;k++)
    {
        cout<<a[k]<<" ";
    }
}
int main()
{
	string a[]={"a","a","a","a","a","a","a","a","a","a","a"};
	int n=11;
	compressString(a,n);
	
}

