#include<iostream>
using namespace std;
void insertionsort(int a[],int n)
{
	int j;
	for(int i=0;i<n;i++)
	{
		int k;
		k=a[i];
		j=i-1;
		while(j>=0 && a[j]>k)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=k;
	}
}
int main()
{
  int n,*a=NULL;
  cout<<"enter number of elements in array"<<endl;
  cin>>n;
  a=new int [n];
  cout<<"enter elements in the array"<<endl;
  for(int i=0;i<n;i++)
  cin>>a[i];
  insertionsort(a,n);
  cout<<"array after sorting: "<<endl;
  for(int i=0;i<n;i++)
  cout<<a[i]<<endl;
  return 0;
}
