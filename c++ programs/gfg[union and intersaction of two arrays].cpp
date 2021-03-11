#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n1,n2;
	map<int,int>mp,mp1;
	cout<<"enter n1 & n2 ";
	cin>>n1>>n2;
	int a[n1],b[n2];
	cout<<"enter array1 elements: ";
	for(int i=0;i<n1;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	cout<<"enter array 2 elements: ";
	for(int i=0;i<n2;i++)
	{
		cin>>b[i];
	}
	cout<<"intersaction of these two arrays is: ";
   for(int i=0;i<n2;i++)
   {
   	if(mp[b[i]]>0)
   	{
   		cout<<b[i]<<" ";
	   }
}
int c;
   cout<<endl;
   cout<<"union of these two arrays is: ";
   for(int i=0;i<n1;i++)
   {
   	cout<<a[i]<<" ";
   }
   for(int i=0;i<n2;i++)
   {
   	if(mp[b[i]]==0)
   	{
   		cout<<b[i]<<" ";
	   }
   }
}
