#include<iostream>
#include<queue>
using namespace std;
struct element
{
	int x;
	int y;
};
bool isdelim(element temp)
{
	if(temp.x=-1 && temp.y==-1)
	return true;
	return false;
}
bool isvalid(int x,int y,int r,int c)
{
	if(x >=0 && y >=0 && x<r && y<c)
	return true;
	return false;
}
bool checkAll(int arr[][50],int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(arr[i][j]==1)
			return true;
		}
	}
	return false;
}
int rottenOrange(int arr[][50],int r,int c)
{
  queue<element>q;
  element temp;
  int ans=0;
  for(int i=0;i<r;i++)
  {
  	for(int j=0;j<c;j++)
  	{
  		if(arr[i][j]==2)
  		{
  			temp.x=i;
  			temp.y=j;
  			q.push(temp);
		  }
	  }
   }
   temp.x=-1;
   temp.y=-1;
   q.push(temp);
  
   while(!q.empty())
   {
   	 bool flag=false;
   while(!isdelim(q.front()))
   {
   	temp=q.front();
   	if(isvalid(temp.x+1,temp.y,r,c) && arr[temp.x+1][temp.y]==1)
    {
	if(flag==false)
   	{
   		ans++;
   	flag=true;
	}
   	arr[temp.x+1][temp.y]=2;
   	temp.x++;
   	q.push(temp);
   	temp.x--;
	}	
    if(isvalid(temp.x-1,temp.y,r,c) && arr[temp.x-1][temp.y]==1)
    {
	if(flag==false)
   	{
   		ans++;
   	flag=true;
	}
   	arr[temp.x-1][temp.y]=2;
   	temp.x--;
   	q.push(temp);
   	temp.x++;
	}	
	if(isvalid(temp.x,temp.y-1,r,c) && arr[temp.x][temp.y-1]==1)
{
	if(flag==false)
   	{
   		ans++;
   	flag=true;
	}
   	arr[temp.x][temp.y-1]=2;
   	temp.y--;
   	q.push(temp);
   	temp.y++;
	}	
	if(isvalid(temp.x,temp.y+1,r,c) && arr[temp.x][temp.y+1]==1)
{
	if(flag==false)
   	{
   		ans++;
   	flag=true;
	}
   	arr[temp.x][temp.y+1]=2;
   	temp.y++;
   	q.push(temp);
   	temp.y--;
	}
	q.pop();	
}
q.pop();
if(!q.empty())
{
	temp.x=-1;
	temp.y=-1;
	q.push(temp);
}
}
return (checkAll(arr,r,c))?-1:ans;
}
int main()
{
	int r,c;
	r=3,c=5;
	int arr[50][50]={{ 2, 1, 0, 2, 1 },
                      { 1, 0, 1, 2, 1 },
                      { 1, 0, 0, 2, 1 } };
    int ans=rottenOrange(arr,r,c);
    cout<<ans;
}
