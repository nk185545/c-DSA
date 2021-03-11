#include <iostream>
#include <string>
using namespace std;

   string X[] = { "", "One ", "Two ", "Three ", "Four ", "Five ","Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ","Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
				"Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };

const string Y[] = {"","", "Twenty ", "Thirty ", "Forty ", "Fifty ","Sixty ", "Seventy ", "Eighty ", "Ninety " };

string convert2digit(int n, string suffix)
{
	if (n == 0) {
		return "";
	}
	if (n > 19) {
		return Y[n / 10] + X[n % 10] + suffix;
	}
	else {
		return X[n] + suffix;
	}
}
string numberToWords( int n)
{
	string res;
	res = convert2digit((n % 100), "");

	if (n > 100 && n % 100) {
		res = "and " + res;
	}
	res = convert2digit(((n / 100) % 10), "Hundred ") + res;
	res = convert2digit(((n / 1000) % 100), "Thousand ") + res;
	res = convert2digit(((n / 100000) % 100), "Lakh, ") + res;
	return res;
}
int main()
{int sal;
	cout<<"enter the salary of employee:"<<endl;
	cin>>sal;
	cout<<"the salary of employee is : "<<numberToWords(sal);

	return 0;
}
