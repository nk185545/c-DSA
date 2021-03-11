#include<iostream>
using namespace std;
class student
{
	protected:
		int rollno;
		public:
		void getrollno(int a)
		{
			rollno=a;
		}
		void putno()
		{
			cout<<"ROLL NUMBER  "<<rollno<<endl;
			
		}
};
class test: virtual public student
{
	protected :
	float x,y;
	public:
		void getmarks(float c,float d)
		{
			x=c;
			y=d;
		}
		void showmarks()
		{
			cout<<"number in mid sem is(out of 30): "<<x<<endl<<"number in end sem is(out of 50): "<<y<<endl;
		}
};
class sports:public virtual student
{
	protected:
		float score;
		public:
			void getscore(float g)
			{
				score=g;
			}
			void showscore()
			{
				cout<<"total score in sports  is(out of 20):  "<<score<<endl;
			}
};
class result:public test,public sports
{
	float total;
	public :
	void display();
};
void result::display()
{
	total=x+y+score;
	putno();
	showmarks();
	showscore();
	cout<<"total score is: "<<total<<endl;
}
int main()
{
	result r;
	r.getrollno(185545);
	r.getscore(19);
	r.getmarks(28,48);
	r.display();
	return 0;
}
