#include<iostream>
using namespace std;
int main()
{
	int arr1[50],arr2[50],merge[100],i,j,size1,size2,size,median[100];
	int k;
	cout<<"enter the size of array 1:";
	cin>>size1;
	cout<<"enter the elements of array1:";
	
		for(int i=0;i<size1;i++)
		cin>>arr1[i];
	
	cout<<"enter the size of array2:";
	cin>>size2;
	cout<<"enter the elements of array2:";
	for(i=0;i<size2;i++)
	cin>>arr2[i];
	for(i=0;i<size1;i++)
	merge[i]=arr1[i];
	size=size1+size2;
	for(i=0,k=size1;k<size && i<size2;i++,k++)
	merge[k]=arr2[i];
	for(i=0;i<size;i++)
	cout<<merge[i]<<"\n";
	if(size%2==0)
	{
	int a=((merge[size/2-1]+merge[(size/2)])/2);
	cout<<"median is : "<<a;}
	if(size%2!=0)
	cout<<"median is: "<<merge[size/2]; 
	return 0;
}
