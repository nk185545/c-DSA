#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n)
{
    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            int flag = 0;
            if( arr[j] > arr[j+1])
            {

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
       int flag;
        if(!flag)
        {
            break;
        }
    }
 cout << "Sorted Array: " ;
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n,*a=NULL;
    cout<<"Enter the size of array"<<endl;
    cin>> n;
    a=new int[n];
    cout << "Enter array elements"<<endl;
    for(int i=0;i<n;i++)
       cin >> a[i];
 bubble_sort(a,n);
}

