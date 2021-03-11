#include<iostream>
using namespace std;
bool isPrime(int n)  
{  
    // Corner cases  
    if (n <= 1)  return false;  
    if (n <= 3)  return true;  
    
    // This is checked so that we can skip   
    // middle five numbers in below loop  
    if (n%2 == 0 || n%3 == 0) return false;  
    
    for (int i=5; i*i<=n; i=i+6)  
        if (n%i == 0 || n%(i+2) == 0)  
           return false;  
    
    return true;  
}  
  
int nextPrime(int N) 
{ 
  
    // Base case 
    if (N <= 1) 
        return 1; 
  
    int prime = N; 
    bool found = false;
    
    while (!found) { 
        prime++; 
  
        if (isPrime(prime) && !isPrime(prime-N)) 
            found = true; 
    } 
  
    return	(prime-N); 
} 
  
int main()
{
	int t;
	cin>>t;
	while(t)
	{
		int n;
		cin>>n;
		int arr[n][n];
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-1;j++)
			{
				arr[i][j]=1;
			}
		}
		arr[n-1][n-1]=1;
		int sum=n-1;
		int a=nextPrime(sum);
		for(int i=0;i<n-1;i++)
		{
			arr[i][n-1] =a;
			arr[n-1][i] = a ;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<arr[i][j]<<" ";;
			}
			cout<<endl;
		}
    t--;	
	}
}
