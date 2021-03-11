#include<iostream>
using namespace std;
int main()
{
	int arr[]={1,1,2,3,4,3,5,6,5};
	int count=0;
	int i;
	for(i=0;i<9;i++)
	{
		for(int j=i+1;j<9;j++)
		{
			if(arr[i]==arr[j])
		
			{
			
			count++;
			break;
		}
		}
	}
		cout<<"duplicate elements are:"<<count;
	return 0;
}
