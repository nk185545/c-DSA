#include<iostream>
using namespace std;
int maxsubarraysum(int a[],int arr_size)
{
    int	max_ending_here=0;
	int max_so_far=0;
	for(int i=0;i<arr_size;i++)
	{
		max_ending_here=max_ending_here+a[i];
		if(max_ending_here<0)
		max_ending_here=0;
		if(max_so_far<max_ending_here)
		max_so_far=max_ending_here;
	}
	return max_so_far;
}
int main()
{
	int a[]={-1,2,-4,5,6,0,-3};
	int n=sizeof(a)/sizeof(a[0]);
	int max_sum=maxsubarraysum(a,n);
	cout<<"maximum contiguous sum is:"<<max_sum;
	return 0;
}
