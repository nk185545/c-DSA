#include <bits/stdc++.h> 
using namespace std;
string removestring(string str)
{
	string res="";
    res=res+str[0];
	for(int i=1;i<str.length();i++)
	{
		if(str[i]=='a' && res[res.length()-1]=='a' )
		{
			continue;
		}
-	else if(str[i]=='b')
		{
			continue;
		}
		else
		{
		res=res+str[i];
	}
	}
	return res;
}
int main()
{
	string str;
	cout<<"enter string: ";
	cin>>str;
   string s=removestring(str);
	cout<<s;
}

/-/ aacbccdbsssaba
