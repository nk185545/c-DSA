#include<iostream>
using namespace std;
bool findUnsigned(int grid[9][9] ,int &i,int &j)
{
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        if(grid[i][j]==0)
            return true;
    }
    return false;
}
bool isSafe(int grid[9][9],int row,int column,int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[row][i]==num)
            return false;
    }
    for(int i=0;i<9;i++)
    {
        if(grid[i][column]==num)
            return false;
    }
    int startRow=row-row%3;
    int startColumn=column-column%3;
    for(int i=0;i<3;i++)
    {
    for(int j=0;j<3;j++)
    {
        if(grid[i+startRow][j+startColumn]==num)
            return false;
    }
    }
    if(grid[row][column]!=0)
        return false;
return true;
}
bool sudokuSolve(int grid[9][9],int row,int column)
{
    if(!findUnsigned(grid,row,column))
        return true;
        for(int i=1;i<=9;i++)
        {
            if(isSafe(grid,row,column,i))
            {
                grid[row][column]=i;
                if(sudokuSolve(grid,row,column))
                    return true;
                    grid[row][column]=0;
            }
        }
    return false;
}
void print(int grid[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int grid[9][9]={ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};
                      bool b= sudokuSolve(grid,0,0);
                       if(b==true)
                       print(grid);
                       else{
                        cout<<"no possible";
                       }
    return 0;
}
