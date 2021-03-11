#include<iostream>
using namespace std;
void allSubsets(int arr[],int n,int i,int temp[],int index,int k)
{
	if(i>=n)
    {
    	 for(int x=0;x<index;x++)
      {
          cout<<temp[x]<<" ";
      }
      cout<<endl;
    
      return;
    }
     
    temp[index] = arr[i] ;
    allSubsets(arr,n,i+1,temp,index+1,k);
    allSubsets(arr,n,i+1,temp,index,k);
}
int main()
{
    int arr[]={1,2,3,4};
    int n=4;
    int temp[50];
    int k=3;
    allSubsets(arr,n,0,temp,0,k);
}
