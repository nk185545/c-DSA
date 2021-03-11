#include<iostream>
using namespace std;
struct trie
{
	bool end;
	struct trie* child[26];
 }; 
 typedef struct trie* tptr;
 tptr createNode()
 {
 	tptr root=new struct trie();
 	root->end=false;
 	for(int i=0;i<26;i++)
 	{
 		root->child[i]=NULL;
	 }
	 return root;
 }
 tptr createTrie(tptr root,string str)
 {
 	for(int i=0;i<str.length();i++)
 	{
 		int ch=str[i]-'a';
 		if(root->child[ch]==NULL)
 		{
 		   	root->child[ch]=createNode();
		}
		root=root->child[ch];
	 }
	 root->end=true;
 }
 bool search(tptr root,string str)
 {
 	for(int i=0;i<str.length();i++)
 	{
 		int data=str[i]-'a';
 	    if(root->child[data]==NULL)
		 {
		    return false;	
		 }	
		 root=root->child[data];
	}
	return (root && root->end);
 }
 int main()
 {
 	tptr root=createNode();
 	int n;
 	cin>>n;
 	
 	for(int i=0;i<n;i++)
 	{
 		string str;
 		cin>>str;
 		createTrie(root,str);
	}
	string st;
	cin>>st;
	bool b=search(root,st);
	cout<<b;
	return 0;
 }
