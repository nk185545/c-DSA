#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int maxside ;
int NOM;   //number of mines
int mines[99][2]; //99 is maximum mines
char PlayBoard[25][25];
char RealBoard[25][25];  //remains unchanged during whole program
void printBoard(char arr[25][25],int maxside)
{
	cout<<"   " ;
	for(int i=0;i<maxside;i++)
	{
		if(i<=9) cout<<0<<i<<" ";
		else cout<<i<<" ";
	}
	cout<<endl;
	for(int i=0;i<maxside;i++)
	{
		if(i<=9) cout<<0<<i<<"  ";
		else cout<<i<<"  ";
		for(int j=0;j<maxside;j++)
		{
			if(j<=9) cout<<arr[i][j]<<"  " ;
			else 
			{
				cout<<arr[i][j]<<"  " ;
			}
		}
		cout<<endl;
	}
	
}
void placeMines(char RealBoard[25][25],int maxside,int NOM)
{
	srand(time(0));
	for(int i=0;i<NOM;i++)
	{
		int ran=rand()%(maxside*maxside);
		int row=ran/maxside;
		int col=ran%maxside;
		mines[i][0]=row;
		mines[i][1]=col;
		RealBoard[row][col]='*';
	}
//	printBoard(RealBoard,maxside);
}
void createPlayBoard(int maxside)
{
 for(int i=0;i<maxside;i++)
	{
		for(int j=0;j<maxside;j++)
		{
			
			PlayBoard[i][j]='-';
		}
	}
	return;
}
void createRealBoard(int maxside,int NOM)
{
	for(int i=0;i<maxside;i++)
	{
		for(int j=0;j<maxside;j++)
		{
			
			RealBoard[i][j]='-';
		}
	}
//	printBoard(RealBoard,maxside);
	placeMines(RealBoard,maxside,NOM);
	createPlayBoard(maxside);
}
void replaceMine(char RealBoard[25][25],int x,int y)
{
	for(int i=0;i<maxside;i++)
	{
		for(int j=0;j<maxside;j++)
		{
			if(RealBoard[i][j]=='-')
			{
				RealBoard[i][j]='*';
				RealBoard[x][y]='-';
			}
		}
	}
}
bool isvalid(int x,int y)
{
	if(x<0 || y<0 || x>=maxside || y>=maxside)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int countNeighbour(int x,int y,char RealBoard[25][25])
{
	int cnt=0;
 if(isvalid(x-1,y) &&RealBoard[x-1][y]=='*')
 {
 	cnt++;
	 }
	 if(isvalid(x,y-1) &&RealBoard[x][y-1]=='*')
 {
 	cnt++;
	 }
	 if(isvalid(x,y+1) &&RealBoard[x][y+1]=='*')
 {
 	cnt++;
	 }
	 if(isvalid(x+1,y) &&RealBoard[x+1][y]=='*')
 {
 	cnt++;
	 }
	 if(isvalid(x-1,y-1) &&RealBoard[x-1][y-1]=='*')
 {
 	cnt++;
	 }
	 if(isvalid(x-1,y+1) &&RealBoard[x-1][y+1]=='*')
 {
 	cnt++;
	 }
	 if(isvalid(x+1,y-1) &&RealBoard[x+1][y-1]=='*')
 {
 	cnt++;
	 }
	 if(isvalid(x+1,y+1) &&RealBoard[x+1][y+1]=='*')
 {
 	cnt++;
	 }	
	 return cnt;
}
void PlayMineSweeper()
{ int x,y;
	bool gameover=false;
	int cmi=0;  //current move index
	int moveleft=maxside*maxside-NOM;
	while(gameover==false)
	{
		printBoard(PlayBoard,maxside);
		cout<<"enter your choice: ";
		cin>>x>>y;
		if(cmi==0 && RealBoard[x][y]=='*')
		{
			replaceMine(RealBoard,x,y);
		}
		else if(cmi!=0 && RealBoard[x][y]=='*')
		{
			for(int i=0;i<NOM;i++)
			{
				PlayBoard[mines[i][0]][mines[i][1]] = '*' ;
			}
			printBoard(PlayBoard,maxside);
			cout<<"you have lost!!!!";
			return;
		}
		cmi++;
		moveleft--;
		if(moveleft==0)
		{
			cout<<"you are the winner of the game !!!!"<<endl;
			return;
		}
	int countn=countNeighbour(x,y,RealBoard);
	PlayBoard[x][y]=countn+'0';
	
}
}
int main()
{
	int n;
	cout<<"############  Welcome  To MineSweeper Game############ "<<endl<<endl;
	cout<<"press 1 for Beginner's Level "<<endl;
	cout<<"press 2 for Intermediate Level "<<endl;
	cout<<"press 3 for Hard Level "<<endl;
	cin>>n;
	if(n==1)
	{
		maxside=9;
		NOM=10;
	}
	else if(n==2)
	{
		maxside=16;
		NOM=40;
	}
	else if(n==3)
	{
		maxside=25;
		NOM=99;
	}
	else
	{
		cout<<"Invalid Choice ";
		return 0;
	}
	createRealBoard(maxside,NOM);
	PlayMineSweeper();
}
