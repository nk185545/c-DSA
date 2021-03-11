#include<iostream>
#include<queue>
#define m 8
#define n 8
using namespace std;
bool isvalid(int x,int y)
{
	return (x>=0 && y>=0 && x<m && y< n);
}
void floodFill(int board[][n],int x,int y,int new_color)
{
	int visited[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			visited[i][j]=0;
		}
	}
	queue<pair<int,int> >q;
	q.push({x,y});
	visited[x][y]=1;
	while(!q.empty())
	{
		pair<int,int>coord=q.front();
		int x=coord.first;
		int y=coord.second;
		int prev_color=board[x][y];
		board[x][y]=new_color;
		q.pop();
		if(isvalid(x+1,y) && board[x+1][y]==prev_color && visited[x+1][y]==0)
		{
			q.push({x+1,y});
			visited[x+1][y]=1;
		}
		if(isvalid(x,y+1) && board[x][y+1]==prev_color && visited[x][y+1]==0)
		{
			q.push({x,y+1});
			visited[x][y+1]=1;
		}
		if(isvalid(x-1,y) && board[x-1][y]==prev_color && visited[x-1][y]==0)
		{
			q.push({x-1,y});
			visited[x-1][y]=1;
		}
		if(isvalid(x,y-1) && board[x][y-1]==prev_color && visited[x][y-1]==0)
		{
			q.push({x,y-1});
			visited[x][y-1]=1;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
  int board[m][n]={{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
    int x,y,new_color;
    cin>>x>>y;
    cin>>new_color;
    int prev_color=board[x][y];
	floodFill(board,x,y,new_color);
}
