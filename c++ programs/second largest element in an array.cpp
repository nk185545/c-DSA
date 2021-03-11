#include<iostream>
using namespace std;
int main()
{
	int a[23],largest,secondlargest,s,i;
	int n,ar[45]={0};
	cout<<"enter number of elements in an array: ";
	cin>>n;
	cout<<endl;
	cout<<"enter elements of an array ";
	for(i=0;i<n;i++)
	 cin>>a[i];
	 //largest=a[0];
	// secondlargest=a[1];
	 /*for(i=0;i<6;i++)
	 {
	 	for(int j=i+1;j<=6;j++)
	 	if(a[i]>largest)
	 	{
	 			secondlargest=largest;
	 	largest=a[i];
	 }
	 	else if(a[i] > secondlargest && a[i] != largest)
		  {
	 		
	 		secondlargest=a[i];
		 }
	 }
	 cout<<"greatest element in arrray:"<<largest<<endl;
	 cout<<"second largest element in array: "<<secondlargest<<endl;*/
	 cout<<"enter the number which you wants to insert: ";
	 cin>>s;
	 for(i=0;i<n+1;i++)
	 {ar[i]=a[i];
	 ar[i]=s;
	 cout<<ar[i]<<endl;
	 
}
	 return 0;
}
