#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
	ofstream fout1,fout2;
	const char n=80;
	char name[n];
	fout1.open("country");
	fout2.open("capital");
	for(int i=0;i<10;i++)
	{
		if(fout1.eof()!=0)
		{
			cout<<"exit from country"<<endl;
			exit(1);
		}
		fout1<<name;
		cout<<"capital of"<<name;
		cout<<endl;
			if(fout2.eof()!=0)
		{
			cout<<"exit from capital"<<endl;
			exit(1);
		}
		fout2<<name;
		cout<<name;
		cout<<endl;
		
	}
	return 0;
}
