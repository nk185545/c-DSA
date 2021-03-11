#include<iostream>
#include<algorithm>
using namespace std;
void minimumplatforms(int arr[6],int dep[6],int n)
{
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }
        if (plat_needed > result)
            result = plat_needed;
    }

    cout<<result;
}
int main()
{
    int arr[6]={900, 940, 950, 1100, 1500, 1800};
    int dep[6]={910, 1200, 1120, 1130, 1900, 2000};
    minimumplatforms(arr,dep,6);
}
