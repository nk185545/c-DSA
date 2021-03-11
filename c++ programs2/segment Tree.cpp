#include<iostream>]
#include<cmath>
using namespace std;
int min(int a,int b)
{
	if(a>b)
	return b;
	else
	return a;
}
void createTree(int arr[],int segTree[],int l,int h,int i)
{
	if(l==h)
	{
		segTree[i]=arr[l];
	
	return;
	}
int mid=(l+h)/2;
createTree(arr,segTree,l,mid,2*i+1);
createTree(arr,segTree,mid+1,h,2*i+2);
segTree[i]=min(segTree[2*i+1],segTree[2*i+2]);
}
int range(int segTree[],int ql,int qh,int l,int h,int i)
{
	if(ql<=l && qh>=h)
	return segTree[i];
	if(qh <l || ql>h)
	return INT_MAX;
	int mid=(l+h)/2;
return min(range(segTree,ql,qh,l,mid,2*i+1),range(segTree,ql,qh,mid+1,h,2*i+2));
}
int main()
{
 int arr[15]={-1,2,4,0,5,9};
 int n=6;
 int n1;
 float x=log2(n);
 int y=(int)x;
 if(x==y)
 {
 	n1=2*n-1;
 }
 else
 {
 	n1=(pow(2,y+1))*2-1;
 }
 int segTree[n1];
 int z=(n1+1)/2;
  for(int i=n;i<z;i++)
  {
  	arr[i]=INT_MAX;
  }
 	 createTree(arr,segTree,0,z-1,0);
	 for(int i=0;i<n1;i++)
	 {
	 	cout<<segTree[i]<<" ";
	 }
	 cout<<endl;
	int ans= range(segTree,1,3,0,z-1,0);
cout<<ans;
}
