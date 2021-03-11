#include<iostream>
#include<math.h>
using namespace std;
class conversions
{public:
	int a;
	public:
		void input()
		{
			cout<<"enter the number "<<endl;
			cin>>a;
			cout<<endl;
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
			cout<<endl;
		
	}
};
class hexadecimal:public conversions
{
public:
  void hexa()
{
	int num, temp, i = 1, j, r;
    char hex[50];
    cout << " Enter a decimal number : ";
    cin >> num;
    temp = num;
    while (temp != 0)
    {
        r = temp % 16;
        if (r < 10)
            hex[i++] = r + 48;
        else
            hex[i++] = r + 55;
        temp = temp / 16;
    }
    cout << "\nHexadecimal equivalent of " << num << " is : ";
    for (j = i; j > 0; j--)
        cout << hex[j];
        cout<<endl;
}
public:
	void binarytohexadecimal()
	{
		int hex[1000];
  int i = 1, j = 0, rem, dec = 0, binaryNumber;
	cout << " Input a binary number: "<<endl;
	cin>> binaryNumber;
	cout<<endl;
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
cout<<" The hexadecimal value: ";
  for (j = i - 1; j >= 0; j--)
  {
   if (hex[j] > 9) 
   {
    cout<<(char)(hex[j] + 55)<<"\n";
   } 
   else
   {
    cout<<hex[j]<<"\n";
   }
  }
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
