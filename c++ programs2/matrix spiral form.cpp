#include<iostream>
using namespace std;
void spiralMatrix(int mat[4][5],int m,int n)
{
    int last_row=m-1,last_column=n-1;
    int l=0,k=0;
    while(k<last_row && l<last_column)
    {
        for(int i=l;i<=last_column;i++)
        {
        	cout<<(mat[k][i])<<" ";	
		}

            
       k++;
       for(int i=k;i<=last_row;i++)
       {
       		cout<<(mat[i][last_column])<<" ";
	   }

	   last_column--;
       if(k<=last_row)
       {
           for(int i=last_column;i>=l;i--)
           {
               cout<<(mat[last_row][i])<<" ";
           }

           last_row--;
       }
       if(l<=last_column)
       {
       	   for(int i=last_row;i>=k;i--)
           {
               cout<<(mat[i][l])<<" ";
           }
           l++;
       }
    }
}

int main()
{
    int mat[4][5]={{1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15},
                    {16,17,18,19,20}
                    };
    spiralMatrix(mat,4,5);
}
