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
		void binary()
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
class hexadecimal:public conversions
{
public:
  void hexa()
{int b;
cout<<"enter the number"<<endl;
cin>>b;
	int arr[10],i;
	for(i=0;b>0;i++)
	{
		arr[i]=b%16;
		b=b/16;
		
	}
	for(i=i-1;i>=0;i--)
	cout<<"hexadecimal of given number is:"<<arr[i];
}
public:
	void binarytohexadecimal()
	{
		int hex[1000];
  int i = 1, j = 0, rem, dec = 0, binaryNumber;
	cout << " Input a binary number: ";
	cin>> binaryNumber;
  while (binaryNumber > 0) 
  {
   rem = binaryNumber % 2;
   dec = dec + rem * i;
   i = i * 2;
   binaryNumber = binaryNumber / 10;
  }
   i = 0;
  while (dec != 0) 
  {
   hex[i] = dec % 16;
   dec = dec / 16;
   i++;
	}
	cout<<"hexadecimal of the given numbers is: "<<dec;
}
      };
  int main()
{

	hexadecimal hex;
	hex.input();
     hex.binary();
     hex.hexa();
     hex.binarytohexadecimal();
 return 0; 
}
