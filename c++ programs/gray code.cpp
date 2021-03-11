#include<iostream>
#include<math.h>
using namespace std;
class conversions
{public:
	int a;
	public:
		void input()
		{
			cout<<"enter the number ";
			cin>>a;
		}
	};
	class bina:public conversions
	{public:
		void bin()
		{
			int arr[10],i;
			for(i=0;a>0;i++)
			{
				arr[i]=a%2;
				
					a=a/2;
			}
			cout<<"binary of given decimal digit is :";
			for(i=i-1;i>=0;i--)
			cout<<arr[i];
		
	}
};
class gray:public bina
{
char xor_c(char a, char b) { return (a == b) ? '0' : '1'; } 
char fun(char c) { return (c == '0') ? '1' : '0'; } 

string binarytoGray(string binary) 
{ 
    string gray = ""; 
    gray += binary[0]; 
    for (int i = 1; i < binary.length(); i++) 
        gray += xor_c(binary[i - 1], binary[i]); 
        return gray;
    } 

};
int main()
{
	gray con;
	con.input();
	con.bin();
	con.binarytoGray(std);
	return 0;
}
