#include<iostream>
#include<cmath>
using namespace std;
struct tree
{
	int maxima;
	int minima;
	int sum;
};
int min(int a,int b)
{
	if(a>b)
	return b;
	else
	return a;
}
void createTree(int arr[],struct tree t[],int l,int h,int i)
{
	if(l==h)
	{
		t[i].minima=arr[l];
		t[i].maxima=arr[l];
		t[i].sum=arr[l];
	return;
	}
int mid=(l+h)/2;
createTree(arr,t,l,mid,2*i+1);
createTree(arr,t,mid+1,h,2*i+2);
t[i].minima=min(t[2*i+1].minima,t[2*i+2].minima);
t[i].maxima=max(t[2*i+1].maxima,t[2*i+2].maxima);
t[i].sum=t[2*i+1].sum+t[2*i+2].sum;
}
struct tree range(struct tree t[],int ql,int qh,int l,int h,int i)
{
	struct tree temp,left,right;
	if(ql<=l && qh>=h)
	{
		return t[i];
	}

	if(qh <l || ql>h)
	{
       temp.minima=INT_MAX;
       temp.maxima=INT_MIN;
       temp.sum=0;
       return temp;
	}

	int mid=(l+h)/2;
    left= (range(t,ql,qh,l,mid,2*i+1),range(t,ql,qh,mid+1,h,2*i+2));
   right=(range(t,ql,qh,l,mid,2*i+1),range(t,ql,qh,mid+1,h,2*i+2));
    temp.minima=min(left.minima,right.minima);
    temp.maxima=max(left.maxima,right.maxima);
    temp.sum=left.sum+right.sum;
    return temp;
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
 struct tree t[n1];
 int z=(n1+1)/2;
  for(int i=n;i<z;i++)
  {
  	arr[i]=INT_MAX;
  }
 	 createTree(arr,t,0,z-1,0);
	 struct tree temp;
	temp=range(t,1,3,0,z-1,0);
cout<<temp.maxima<<"  "<<temp.minima<<" "<<temp.sum;
}
