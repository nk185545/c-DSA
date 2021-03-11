#include<iostream>
using namespace std;
int main()
{
	char str[100];
	char* ptr;
	cout<<"enter a string"<<endl;
	cin.get(str,100);
	ptr=str;
	cout<<"entered string is: "<<endl;
	while(*ptr!='/0')
	cout<<(*ptr++);
	return 0;
	
}
