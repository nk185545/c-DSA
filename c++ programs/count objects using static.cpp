#include<iostream>
using namespace std;
class account
{
	public:string name;
	int accno;
	int ifsccode;
	static float rateofinterest;
	static string  companyname;
	static int count;
	public:
		account(string name,int accno,int ifsccode)
		{
			this->name=name;
			this->accno=accno;
			this->ifsccode=ifsccode;
		count++;
		}
		void show()
		{
			cout<<"name of accountholder is:  "<<name<<endl<<"account no is=  "<<accno<<endl<<"ifsccode is:  "<<ifsccode<<endl;
			cout<<"rate of interest is:  "<<rateofinterest<<endl<<"company name is:   "<<companyname<<endl;
		
		}
};
float	account::rateofinterest=6.5;
string	account::companyname="microsoft";
int account::count;

int main()
{

account a1=	account("neetu",18456758,1056);
account a2=	account("megha",18457758,1043);
a1.show();
a2.show();
cout<<"total numberrs of objects are L:"<<account::count<<endl;
return 0;

}
