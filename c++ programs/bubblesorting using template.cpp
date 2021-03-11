#include <iostream> 
using namespace std; 
template <class T> 
void bubbleSort(T a[], int n)
 { 
    for (int i = 0; i < n - 1; i++) 
        for (int j = n - 1; i < j; j--) 
            if (a[j] < a[j - 1]) 
              swap(a[j], a[j - 1]); 
} 
template<class x>
void swap(x &a,x &b)
{
	x temp=a;
	a=b;
	b=temp;
}
 int main()
  { 
    int a[5] = {10, 50, 30, 40, 20}; 
    float y[5]={1.1,2.2,3.3,4.4,5.5};
    int n = sizeof(a) / sizeof(a[0]); 
    bubbleSort(a, 5); 
    cout << " Sorted array : "; 
    for (int i = 0; i < n; i++) 
        cout << a[i] << " "; 
    cout << endl; 
     cout << " Sorted array : "; 
    for (int i = 0; i < n; i++) 
        cout << y[i] << " "; 
    cout << endl; 
   
  return 0; 
} 
