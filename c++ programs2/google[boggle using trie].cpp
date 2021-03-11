#include<iostream>
#include<vector>
using namespace std;
struct triNode
{
	bool end;
	struct triNode* child[26];
};
typedef struct triNode* tptr;
tptr createNode()
{
	tptr root=new struct triNode;
	root->end=false;
	for(int i=0;i<26;i++)
	{
		root->child[i]=NULL;
	}
	return root;
}
tptr createTrie(tptr root,string str)
{
	tptr temp=root;
	for(int i=0;i<str.length();i++)
	{
		int id=str[i]-'A';
		if(root->child[id]==NULL)
		{
			root->child[id]=createNode();
		}
		root=root->child[id];
	}
	root->end=true;
	return temp;
}
bool isSafe(int i,int j,vector<vector<bool> >visited,int rows,int columns)
{
	return (i>=0 && j>=0 && i<rows&& j<columns && !visited[i][j]);
}
void searchWord(vector<vector<char> >boggle,vector<vector<bool> > &visited,tptr root,string res,int i,int j)
{
	if(root->end==true)
	{
		cout<<res<<endl;
	}
	int rows=boggle.size();
	int columns=boggle[0].size();
	if(isSafe(i,j,visited,rows,columns))
	{
	 visited[i][j]=true;
	 for(int k=0;k<26;k++)
	{
		if(root->child[k]!=NULL)
		{
			char ch=(char)k+(char)'A';
			if(isSafe(i-1,j+1,visited,rows,columns) && boggle[i-1][j+1]==ch)
			{
				searchWord(boggle,visited,root->child[k],res+ch,i-1,j+1);
			}
			if(isSafe(i+1,j-1,visited,rows,columns) && boggle[i+1][j-1]==ch)
			{
				searchWord(boggle,visited,root->child[k],res+ch,i+1,j-1);
			}
			if(isSafe(i-1,j,visited,rows,columns) && boggle[i-1][j]==ch)
			{
				searchWord(boggle,visited,root->child[k],res+ch,i-1,j);
			}
			if(isSafe(i,j-1,visited,rows,columns) && boggle[i][j-1]==ch)
			{
				searchWord(boggle,visited,root->child[k],res+ch,i,j-1);
			}
			if(isSafe(i-1,j-1,visited,rows,columns) && boggle[i-1][j-1]==ch)
			{
				searchWord(boggle,visited,root->child[k],res+ch,i-1,j-1);
			}
			if(isSafe(i+1,j,visited,rows,columns) && boggle[i+1][j]==ch)
			{
				searchWord(boggle,visited,root->child[k],res+ch,i+1,j);
			}
			if(isSafe(i+1,j+1,visited,rows,columns) && boggle[i+1][j+1]==ch)
			{
				searchWord(boggle,visited,root->child[k],res+ch,i+1,j+1);
			}
			if(isSafe(i,j+1,visited,rows,columns) && boggle[i][j+1]==ch)
			{
				searchWord(boggle,visited,root->child[k],res+ch,i,j+1);
			}
		}
	     visited[i][j]=false;
	}	
}
}
void findWord(vector<vector<char> >boggle,tptr root)
{
	string res="";
	int m=boggle.size();
	int n=boggle[0].size();
	tptr pchild=root;
	vector<vector<bool> >visited(m,vector<bool>(n,false));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int id=boggle[i][j]-'A';
			if(pchild->child[id]!=NULL)
			{
            res=res+boggle[i][j];
			searchWord(boggle,visited,pchild->child[id],res,i,j);
			res="";
			}
	}
}
}
int main()
{
	int n;
	cin>>n;
	tptr root=createNode();
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		root=createTrie(root,s);
	}
	vector<vector<char> >boggle;
	vector<char>vec1,vec2,vec3;
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
	findWord(boggle,root);
}
