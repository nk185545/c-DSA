#include<iostream>
#include<map>
using namespace std;
void nextclosestTime(string str)
{
	 map<int,int>mp;
	string s=str.substr(0,2);
	int s1=s[0]-'0';
	int s2=s[1]-'0';
	mp[s1]++;
	mp[s2]++;
    int l1=s1*10+s2;
    s=str.substr(3);
    s1=s[0]-'0';
    s2=s[1]-'0';
    mp[s1]++;
    mp[s2]++;
    int minutes=l1*60+(s1*10+s2);
   while(true)
   {
   	minutes=(minutes+1)%(24*60);
   	bool isvalid=true;
   	int arr[]={minutes/60/10,minutes/60%10,minutes%60/10,minutes%60%10};
   	for(int i=0;i<4;i++)
   	{
   		if(mp[arr[i]]==0)
   		{
   		  	isvalid=false;
	   }
   }
    if(isvalid)
    {
    	cout<<"next time is: "<<arr[0]<<arr[1]<<" : "<<arr[2]<<arr[3];
    	return;
	}
}
}
int main()
{
	string str;
	cout<<"enter time : ";
	cin>>str;
	nextclosestTime(str);
}
