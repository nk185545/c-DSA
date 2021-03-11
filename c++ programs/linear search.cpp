#include <iostream>
using namespace std;
int main() 
{
   int s, a[20], n,i;
   cout<<"enter the total number of elements :  ";
   cin>>n;
   cout<<"\n enter the elements of array:";
   for(i=0;i<n;i++)
   cin>>a[i];
   cout<<"\nenter the element to be searched: ";
   cin>>s;
   for (i = 0; i < n; i++)
    {
      if (a[i] == s) {
         cout<<"the element is present in the array at index  "<<i+1<<endl;
         break;
      }
   }
   if (i== n)
      cout<<"the element is not present in the array ";
   return 0;
}
