#include<iostream>
#include<cstdlib>
using namespace std;
int main()
 {
	int n,  temp,i;
	float a[100], avg[100], sum=0;
	cout << ("Enter the number of elements to be entered: ");
	cin >> n;
	cout << ("The elements of array: ");
	for (i = 0; i < n; i++) {
		a[i] = (rand() % 100+1);
		cout << a[i] << endl;
	}
	avg[0]= a[0];
	for(i=1; i<n; i++){
		for (int j = 0; j <= i; j++) {
			sum = a[j] + sum; }
			avg[i] = sum / (i + 1); }
	cout << "The average array: " << endl;
		for ( i = 0; i < n; i++) {
			cout << avg[i] << endl;
		}
		return 0;
	}
