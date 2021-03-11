#include<iostream>
using namespace std;
#define INT_MAX 2147483647
void merge(int arr[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int leftArr[n1+1];  // left sub array
	int rightArr[n2+1]; // right sub array
	for(int i=0;i<n1;i++)
	{
		leftArr[i] = arr[p+i] ;
	}
	for(int i=0;i<n2;i++)
	{
		rightArr[i] = arr[q+1+i] ;
	}

	leftArr[n1] = INT_MAX ;
	rightArr[n2] = INT_MAX ;
	int i=0 ;
	int j=0 ;
	
	for(int k=p;k<=r;k++)
	{
		if(leftArr[i]<=rightArr[j])
		{
			arr[k]=leftArr[i];
			i++;
		}
		else
		{
			arr[k]=rightArr[j];
			j++;
		}
	}
	
	return ;
	
}

void mergeSort(int arr[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2 ;
		mergeSort(arr,p,q) ;
		mergeSort(arr,q+1,r) ;
		merge(arr,p,q,r) ;
	}
}

int BinarySearch(int arr[],int low,int high,int element)
{
	if(low<=high)
	{
		int mid = (low+high)/2 ;
		if(arr[mid]==element)
		{
			return mid ;
		}
		else if(arr[mid]>element)
		{
		return	BinarySearch(arr,low,mid-1,element) ;
		}
		else
		{
		return	BinarySearch(arr,mid+1,high,element) ;
		}
	}
	return -1 ;
}

int main()
{
	cout<<"Welcome.... !!! "<<endl<<endl;
	
	int n ;
	cout<<"Enter number of elements : "<<endl;
	cin>>n ;
	int arr[n] ; // array for store the (Integer) data 
	
	cout<<"Enter the elements : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i] ;
	}

	
	// Now sort the array using " MergeSort "
	
	mergeSort(arr,0,n-1) ;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" " ;
	}
	
	// Now this array has been sorted
	// Now you can search elements
	
	cout<<"\n Now u can enter elements for search [ if u want to exit , type -1 ] . "<<endl;
	int x ;
	cin>>x ;
	while(x!=-1)
	{
		int ans = BinarySearch(arr,0,n-1,x) ;
		if(ans!=-1) cout<<"Element is found at "<<(ans+1)<<" position . "<<endl;
		else cout<<"Element is not found ."<<endl;
		
		cin>>x ;
	}
	cout<<endl<<"-----------------------------------------------"<<endl;
	cout<<"Thanks of using this Application ! "<<endl;
	
	return 0;
}
/*North and Middle Andaman
1	0

South Andaman	
49	17

Foreign Evacuees	
385	293

Anantapur	
1371	662

Chittoor	
891	550

East Godavari	
1002	666

Guntur	
1193	624

Krishna	
1331	701

Kurnool	
1787	770

Other State	
1865	734

Prakasam	
313	164

S.P.S. Nellore	
579	248

Srikakulam	
62	21

Visakhapatnam	
505	271

Vizianagaram	
145	101

West Godavari	
875	703

Y.S.R. Kadapa	
794	513

Anjaw	
0	0
Changlang	
78	52

East Kameng	
0	0

East Siang	
10	0

Kamle	
0	0

Kra Daadi	
0	0

Kurung Kumey	
0	0

Lepa Rada	
1	1

Lohit	
4	1

Longding	
4	3
*/
