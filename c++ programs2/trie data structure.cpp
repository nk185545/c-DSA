#include<iostream>
using namespace std;
struct tnode
{
	bool end;
	struct tnode* child[26];
};
typedef struct tnode* tptr;
tptr create_node()
{
	tptr root=new struct tnode();
	root->end=false;
	for(int i=0;i<26;i++)
	{
		root->child[i]=0;
	}
	return root;
}
tptr create_trie(tptr t,string str)
{
	for(int i=0;i<str.length();i++)
	{
		int id=str[i]-'a';
		if(t->child[id]==NULL)
		{
			t->child[id]=create_node();
		}
		t=t->child[id];
	}
	t->end=true;
}
bool search(tptr t,string str)
{
	for(int i=0;i<str.length();i++)
	{
		int id=str[i]-'a';
		if(t->child[id]==NULL)
		{
			return false;
		}
		t=t->child[id];
	}
	return (t && t->end);
}
int main()
{
	tptr root=NULL;
	root=create_node();
	int n;
	cout<<"how many strings you want to enter: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		create_trie(root,str);
	}
	string s;
	cout<<"enter the string you want to search: ";
	cin>>s;
	bool b=search(root,s);
	if(b==true)
	{
		cout<<"word is present in this dictionary";
	}
	else
	{
		cout<<"word is not present in this dictionary";
	}
}
