#include<iostream>
using namespace std;
#define INT_MAX 2147483647
struct covid 
{
	string dist; //name of the district
	int c_cases; //confirmed cases
	int a_cases; //active case
};
void merge(struct covid data[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	struct covid leftdata[n1+1];  // left sub array
	struct covid rightdata[n2+1]; // right sub array
	for(int i=0;i<n1;i++)
	{
		leftdata[i] = data[p+i] ;
	}
	for(int i=0;i<n2;i++)
	{
		rightdata[i] = data[q+1+i] ;
	}

	leftdata[n1].dist = "ZZZZZZZ" ;
	rightdata[n2].dist = "ZZZZZZZ" ;
	int i=0 ;
	int j=0 ;
	
	for(int k=p;k<=r;k++)
	{
		if(leftdata[i].dist<=rightdata[j].dist)
		{
			data[k]=leftdata[i];
			i++;
		}
		else
		{
			data[k]=rightdata[j];
			j++;
		}
	}
	
	return ;
	
}
void mergeSort(struct covid data[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2 ;
		mergeSort(data,p,q) ;
		mergeSort(data,q+1,r) ;
		merge(data,p,q,r) ;
	}
}
int BinarySearch(struct covid data[],int low,int high,string element)
{
	if(low<=high)
	{
		int mid = (low+high)/2 ;
		if(data[mid].dist==element)
		{
			return mid ;
		}
		else if(data[mid].dist>element)
		{
		return	BinarySearch(data,low,mid-1,element) ;
		}
		else
		{
		return	BinarySearch(data,mid+1,high,element) ;
		}
	}
	return -1 ;
}
int main()
{
	struct covid data[1000];
	int n=0;
	cout<<"Enter district , confirm_cases , active_cases [press -1 to stop the input ] : "<<endl;
	while(1)
	{
		string str;
		cin>>str;
		if(str=="-1")
		{
			break;
		}
		data[n].dist=str;
		cin>>data[n].c_cases;
		cin>>data[n].a_cases;
		n++;
	}
	mergeSort(data,0,n-1) ;
	//for(int i=0;i<n;i++)
	//{
	//	cout<<data[i].dist<<"  "<<data[i].c_cases<<"  "<<data[i].a_cases<<endl;
	//}
		cout<<"\n Now u can enter city/district for search [ if u want to exit , press -1 ] . "<<endl;
	string x ;
	cin>>x ;
	while(x!="-1")
	{
		int ans = BinarySearch(data,0,n-1,x) ;
		if(ans!=-1)
		{
		  cout<<"City/District Name: "<<x<<endl;
		  cout<<"Confirmed Cases: "<<data[ans].c_cases<<endl;
		  cout<<"Active Cases: "<<data[ans].a_cases<<endl;
	}
		
		else
		{
		  cout<<"District/city Data Doesnot Find"<<endl;
	}
	cin>>x;
	}	
}
/*
Jaipur 
900 
600

Jodhpur 
67  
56

Bharatpur 
150 
100

Jaisalmer 
23 
10

Udaipur 
25 
19

Warangal 
100 
15

Surat  
90  
67

Nasik 
82 
56

Pune 
45 
23

Rajasthan  
17660 
13618

Maharashtra 
17000 
7610

TamilNadu 
86224 
47749

Delhi 
85161 
56235

Gujarat 
319 
232

Ajmer	
449	
14
	
Alwar	
352	
5
	
Banswara 
92	
2
	
Baran	
62	
4	

Barmer	
192	
2	

Bhilwara	
227	
3

Bikaner	
189	
7	

Bundi	
10	
0	
Chittorgarh	
204	
6	
Churu	
247	
2	

Dausa	
104	
2	

Dholpur	
402	
3
	
Dungarpur	
414	
0
	
Ganganagar	
40	
1
	
Hanumangarh	
48	
0	

Jaisalmer	
98	
0	

Jalore	
230	
2	

Jhalawar	
367	
0
	
Jhunjhunu	
308	
1	

Jodhpur	   
2414	 
30	

Karauli	
70	
4	
Kota	
555	
19
	
Nagaur	
597	
12
	
Pali	
945	
8
	
Pratapgarh	
14	
1	

Rajsamand	
199	
1	

SwaiMadhopur	
75	
5
	
Sikar	
443	
5

*/
