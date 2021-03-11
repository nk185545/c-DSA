#include<iostream>
#include<map>
#include<vector>
using namespace std;
bool isDictContains(string res, map<string,int> mp)
{
	return (mp[res]>0);
}
void findWordsUtil(vector<vector<char> > boggle,int i,int j,string &res,vector<vector<bool> >&visited, map<string,int> mp)
{
	visited[i][j]=true;
	res=res+boggle[i][j];
	if(isDictContains(res,mp))
	{
		cout<<res<<endl;
	}
	int a=boggle.size();
	int b=boggle[0].size();
	for(int r=i-1;(r<=i+1 )&&(r<a);r++)
	{
		for(int c=j-1;c<=j+1 && c<b;c++)
		{
			if(r>=0 && c>=0  && visited[r][c]==false )
			{
				findWordsUtil(boggle,r,c,res,visited,mp) ;
			}
		}
	}
	res.erase(res.length()-1);
	visited[i][j]=false;
}
void findWords(vector<vector<char> >boggle,int rows,int columns, map<string,int> mp)
{
	string res="";
	vector<vector<bool> >visited(rows,vector<bool>(columns,false));

	for(int i=0;i<boggle.size();i++)
	{
		for(int j=0;j<boggle[0].size();j++)
		{
			
			findWordsUtil(boggle,i,j,res,visited,mp);
		}
	}
}
int main()
{
//-------------------------------------
	vector<vector<char> >boggle ;
	vector<char> vec1,vec2,vec3;
	vec1.push_back('G');
	vec1.push_back('I');
	vec1.push_back('Z');
	vec2.push_back('U');
	vec2.push_back('E');
	vec2.push_back('K');
	vec3.push_back('Q');
	vec3.push_back('S');
	vec3.push_back('E');
	boggle.push_back(vec1) ;
	boggle.push_back(vec2) ;
	boggle.push_back(vec3) ;
//----------------------------------------	
    vector<string>dict ;
    dict.push_back("GEEKS") ;
    dict.push_back("FOR") ;
    dict.push_back("QUIZ") ;
    dict.push_back("GO") ;
//-------------------------------------------    
    map<string,int>mp;
    for(int i=0;i<dict.size();i++)
    {
    	mp[dict[i]]++;
	}
    int rows=boggle.size();
    int columns=boggle[0].size();
    findWords(boggle,rows,columns,mp);
}
