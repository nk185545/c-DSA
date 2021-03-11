#include<iostream>
#include<string>
using namespace std;
struct student
{
	string name;
	int rollno;
	float cgpi;
	int semester;
}s[6];
void enterdetails()
{
	cout<<"******** ENTER DETAILS OF THE STUDENTS********"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"enter the name of student "<<i+1<<" ";
		cin>>s[i].name;
		cout<<"enter the ROLL Number of student "<<i+1<<" ";
		cin>>s[i].rollno;
		cout<<"enter the semester of student "<<i+1<<" ";
		cin>>s[i].semester;
		cout<<"enter the CGPI of student "<<i+1<<" ";
		cin>>s[i].cgpi;
	}
}
void showdetails()
{  int k;   
cout<<"*******DETAILS OF THE STUDENTS********"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Name of the student "<<i+1<<" is: "<<s[i].name<<endl;
		cout<<"Roll Number of the student "<<i+1<<" is: "<<s[i].rollno<<endl;
		cout<<"Semester of the student "<<i+1<<" is: "<<s[i].semester<<endl;
    	cout<<"CGPI of the student "<<i+1<<" is: "<<s[i].cgpi<<endl;
}
}
void part1()
{
	int k;
 cout<<"******STUDENT WITH CGPI GREATER THAN K*******"<<endl;
	cout<<"enter the value of k(CGPI greater than k):\n";
	cin>>k;
	cout<<"list of student CGPI greater than "<<k<<endl;
	for(int i=0;i<5;i++)
	{
		if(s[i].cgpi>k)
		{
		  cout<<"student Nmae:  "<<s[i].name<<endl;
		  cout<<"student ROLL Nummber:  "<<s[i].rollno<<endl;
		  cout<<"student semester:  "<<s[i].semester<<endl;
		  cout<<"student CGPI:  "<<s[i].cgpi<<endl;	
		}
		}	
}
void part2()
{
	cout<<"******INSERT NEW RECORD AT pth POSITION********"<<endl;
	int p;
	struct student st;
		for(int i=4;i>=p-1;i--)
		s[i+1]=s[i];
		cout<<"enter the Pth position"<<endl;
		cin>>p;
	cout<<"enter the details: \n";
		cout<<"enter the name of student "<<" ";
		cin>>st.name;
		cout<<"enter the ROLL Number of student "<<" ";
		cin>>st.rollno;
		cout<<"enter the semester of student "<<" ";
		cin>>st.semester;
		cout<<"enter the CGPI of student "<<" ";
		cin>>st.cgpi;
		cout<<"after insert a new record  "<<endl;
		s[p-1]=st;
		for(int i=0;i<6;i++)
		{
			cout<<"student Nmae:  "<<s[i].name<<endl;
		  cout<<"student ROLL Nummber:  "<<s[i].rollno<<endl;
		  cout<<"student semester:  "<<s[i].semester<<endl;
		  cout<<"student CGPI:  "<<s[i].cgpi<<endl;	
		}
}
int main()
{
	enterdetails();
	showdetails();
	part1();
	part2();
	return 0;
}
