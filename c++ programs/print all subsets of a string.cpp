#include<iostream>
using namespace std;
void allSubsets(string str,int n,int i,char res[],int index,int k)
{
	
    if(index==k)
    {
    	for(int x=0;x<k;x++)
          cout<<res[x];
      cout<<endl;
      return;
    }
    
    if(i>=n)
    {
      return;
    }
    res[index]=str[i];
    allSubsets(str,n,i+1,res,index+1,k);
    allSubsets(str,n,i+1,res,index,k);
}
int main()
{
    string st="abcde";
    int n=5;
    char str[50];
    int k=3;
    allSubsets(st,n,0,str,0,k);
}
