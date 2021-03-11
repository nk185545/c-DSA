#include<iostream>
using namespace std;
int merge(int a[],int p,int q,int r)
{
  int n1,n2;
  int i,j;
  n1=q-p+1;
  n2=r-q;
  int L[n1+1],R[n2+1];
  for(i=1;i<=n1;i++)
  L[i]=a[i+p-1];
  for(j=1;j<=n2;j++)
  R[j]=a[j+q];
  i=1;j=1;
 L[n1+1]= {10000};
 R[n2+1]={10000};
  for(int k=p;k<=r;k++)
  {
  	if(L[i]<=R[j])
  	{
  		a[k]=L[i];
  		i++;
	  }
  	else
  	{
  		a[k]=R[j];
  		j++;
	  }
  }
 }
 int merge_sort(int a[],int p,int r)
 {
 	if(p<r)
 	{
 		int q=(p+r)/2;
	 merge_sort(a,p,q);
	 merge_sort(a,q+1,r);
	 merge(a,p,q,r);
  } 
}
  int main()
  { 
  	int n,a[200];
  	cout<<"enter total number of elements in the array"<<endl;
  	cin>>n;
  	cout<<"enter elements of the array:  "<<endl;
  	for(int i=0;i<n;i++)
  	cin>>a[i];
  	cout<<"sorted ARRAY IS:"<<endl;
  	merge_sort(a,1,n);
  	for(int i=1;i<=n;i++)
  	cout<<a[i]<<endl;
  	return 0;
  }
