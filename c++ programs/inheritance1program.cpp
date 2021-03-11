#include<iostream>
using namespace std;
class shape
{
	
	public:
			void getwidth(int w)
			{
			width=w;}
			getheight(int h){
			height=h;}
			protected:
				int width;
				int height;
};
class rect:public shape
{public:
	int getarea()
	{
	return (width*height);}	
};
class square:public shape
{
	public:int getarea()
	{if(width==height)
		return(width*width);
		else return 0;
	}
};
	int main()
	{
		rect r;
		square s;
		r.getwidth(6);
		r.getheight(6);
		s.getwidth(8);
		s.getheight(8);
		cout<<"area is   "<<r.getarea()<<endl;
		cout<<"area is   "<<s.getarea()<<endl;
	return 0;
	}

