#include<iostream>
using namespace std;
bool isSafe(int x,int y,int sol[8][8])
{
    if(x>=0 && y>=0 && x<8 && y<8 && sol[x][y]==-1)
        return true;
    else return false;
}
bool solveKT(int x,int y,int movei,int sol[8][8],int xMove[8],int yMove[8])
{
    if(movei==64)
        return true;
    for(int i=0;i<8;i++)
    {
        int x_next=x+xMove[i];
        int y_next=y+yMove[i];
    if(isSafe(x_next,y_next,sol))
    {
     sol[x_next][y_next]=movei;
    if(solveKT(x_next,y_next,movei+1,sol,xMove,yMove)==true)
        return true;
    else sol[x_next][y_next]=-1;
}
    }
    return false;
}
void print(int sol[8][8])
{
    for(int i=0;i<8;i++)
    {

        for(int j=0;j<8;j++)
        {
            cout<<sol[i][j]<<" ";
        }
    cout<<endl;
}
}
void knightTour()
{
    int sol[8][8];
    for(int i=0;i<8;i++)
    {

        for(int j=0;j<8;j++)
        {
            sol[i][j]=-1;
        }
    }
    sol[0][0]=0;
    int xMove[8] = { 2, -1, 1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    if(solveKT(0,0,1,sol,xMove,yMove)==true)
    {
        print(sol);
    }
    else{
        cout<<" no solution exist";
        return;
    }
}
int main()
{
   knightTour();
}
