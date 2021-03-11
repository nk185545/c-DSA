#include<iostream>
using namespace std;
class Address{
	public:
		string addresssline,city,state;
		Address(string addressline,string city,string state)
		{
			this->addressline=addressline;
			this->city=city;
			this->state=state;
		}
};
class employee{
	private:Address*address;
	public:
		int id;
		string name;
		employee(int id,string name,Address*address)
		{
			this->id=id;
			this->name=name;
			this->address=address;
		}
		void display()
		{
			cout<<id<<" "<<name<<" "<<address ->addressline<<address->city<<" "<<address->state<<endl;
		}
};
int main()
{
	Address a1=Address("101,bhavyaa tower","jaipur","pratapnagar");
	employee e1=employee(185545,"neetu",&a1);
	e1.display();
return 0;
}
		
		
		
		
		
		
		
		
		
		
