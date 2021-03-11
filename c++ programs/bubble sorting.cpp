#include<iostream>
using namespace std;
int main()
{
	int arr[5]={34,56,67,23,12};
	int i,j,a,b,temp;
	for(i=1;i<5;i++)
	{
		for(j=0;j<4;j++)
		if(arr[j]>arr[j+1])
		{
		temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
}
}
for(j=0;j<5;j++)
cout<<arr[j]<<endl;
return 0;
}
