#include <iostream> 
using namespace std; 
class prime
{
  private:
	int i;
	int j; 
        public:
           int happy(int n, int p) 
                  { 
                    int s= 0; 
                      while (n > 0 && n % p == 0) 
					  { 
                        n /= p; 
                        s++; 
                             }
							 return s; 
                         }
                         
                   int getCount(int l, int r, int p) 
                        { 
                              int count=0; 
                           for (int i = l; i <= r; i++)	
                         count +=happy(i,p);
						 return count; 
                        } 
                    };
	int main() 
     { int l,r,p;
    cout<<"enter value of lower limit: "<<endl;
    cin>>l;
    cout<<"enter upper limit: "<<endl;
    cin>>r;
    cout<<"enter the prime number which you want to count: "<<endl;
    cin>>p;
    prime ne;
    cout<<"the prime number "<<p<<"occured "<<ne.getCount(l, r, p)<<"  number of times";
    return 0; 
}

