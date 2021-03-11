#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string ch[]={"zero","one","two","three","four","five","six","seven","eigth","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	string tens[]={"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	string doubl[]={"hundred","thousand","lakh"};
	
	int num;
	cout<<"enter the number: ";
	cin>>num;
	if(num<20)
	cout<<ch[num];
	if(num>=20 && num<100)
	{
		string str=tens[num/10]+ch[num%10];
		cout<<str;
	}
	if(num>=100 && num<1000)
	{
		string st=ch[num/100]+doubl[0]+ch[num%100];
		cout<<st;
	}
	if(num>=1000 && num<10000)
	{int p=num%1000;
	string s=ch[num/1000]+doubl[1]+ch[p/100]+doubl[0]+ch[p%100];
	cout<<s;
	}
	
	return 0;

}
