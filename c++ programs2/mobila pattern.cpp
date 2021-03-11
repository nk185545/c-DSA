#include<iostream>
#include<map>
#include<vector>
#include<iterator>
using namespace std;
map<string,string>mp;
string to_string(int n)
{
	string s="";
	while(n>0)
	{
		int x=n%10;
		n=n/10;
		s=char(x+'0')+s;
	}
	return s;
}
void calculateMap()
{
	
  int cnt=1;
  int t=0;
  int j=1;
  for(int i=0;i<26;i++)
  {
  	if(cnt<=3)
  	{
  		t=t*10+j;
  		string s1=to_string(t);
  		mp[s1]=char(97+i);
  		cnt++;
	  }
	  else
	  {
	  	cnt=1;
	  	j++;
	  	t=0;
	  	t=t*10+j;
	  	string s1=to_string(t);
	  	mp[s1]=char(97+i);
	  	cnt++;
	  }
  }
  return;
}
void keypad(vector<string>&v,string str,string res)
{
	if(str.length()==0)
	{
		v.push_back(res);
		return;
	}
	for(int j=0;j<str.length();j++)
	{
		string st=str.substr(0,j+1);
		if(mp.find(st)!=mp.end())
		{
			keypad(v,str.substr(j+1),res+mp[st]);
		}
	}
}
vector<string> letterCombinations(string str) 
{
  calculateMap();
  vector<string>v;
  string res="";
  keypad(v,str,res);
  return v;
}


int main()
{
	/* 
	Question : Guess the word 
	 
		You are given a number string(eg."22444","23",etc).
		Your task is to find all the words can be typed using this combination on a keypad phone.
		eg. 11 can be used for "b" and "aa" both
		
		Sample input1 : "22444"
		
		Sample input2 : "23"
		
		Sample Output1 :
		aaggg
		aagh
		aahg
		aai
		bggg
		bgh
		bhg
		bi
		
		Sample Output2 :
		ad
	
	*/
	string str;
	cin >> str;
	vector<string> v = letterCombinations(str);
	for(int i=0;i<v.size();i++)
	{
	cout << v[i] << "\n";
	}
	return 0;
}
