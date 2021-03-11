#include<iostream>
#include<math.h>
using namespace std;
void createSegment(int segment[],int arr[],int l,int h,int i)
{
    if(l==h)
	{
	  segment[i]=arr[l];
	  return;	
	}	
	int mid=(l+h)/2;
	createSegment(segment,arr,l,mid,2*i+1);
	createSegment(segment,arr,mid+1,h,2*i+2);
	segment[i]=segment[2*i+1]+segment[2*i+2];
}
int range(int segment[],int ql,int qr,int l,int h,int i)
{
	if(ql>h || qr<l)
	{
		return 0;
	}
	if(ql<=l && qr>=h)
	return segment[i];
	int mid=(l+h)/2;
	return range(segment,ql,qr,l,mid,2*i+1)+range(segment,ql,qr,mid+1,h,2*i+2);
}
int main()
{
	int n;
	cin>>n;
	int arr[25];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	float x=log2(n);
	int y=int(x);
	int n1;
	if(x==y)
	{
		n1=2*n-1;
	}
	else
	{
		n1=pow(2,y+1)*2-1;
	}
	int mid=(n1+1)/2;
	int segment[n1];
	for(int i=n;i<mid;i++)
	{
		arr[i]=0;
	}
	createSegment(segment,arr,0,mid-1,0);
	for(int i=0;i<n1;i++)
	 {
	 	cout<<segment[i]<<" ";
	 }
	 cout<<endl;
	int ans= range(segment,1,3,0,mid-1,0);
cout<<ans;
}
