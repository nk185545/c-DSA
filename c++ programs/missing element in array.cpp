#include<iostream>
using namespace std;
int main()
{
	int arr[6]={2,4,6,1,5,7};
	int total=(7*8)/2;
	for(int i=0;i<6;i++)
	total-=arr[i];
	cout<<"missing element is:"<<total;	
	return 0;
}
