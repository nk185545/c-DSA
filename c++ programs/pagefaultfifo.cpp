#include<iostream>
using namespace std;
class pagefaultfifo
{
	public:
		void page()
		{
    int i,j,n,a[50],frame[10],no,k,avail,count=0;
    cout<<"\n enter the number of pages :\n";
    cin>>n;
    cout<<"\n enter the page number :\n";
    for(i=1;i<=n;i++)
    cin>>a[i];
    cout<<"\n enter the number of frames :";
    cin>>no;
    for(i=0;i<no;i++)
    frame[i]= -1;
    j=0;
    cout<<"\treference string\t page frames\n";
    for(i=1;i<=n;i++)
    {
    cout<<"\t\t"<<a[i];
    avail=0;
    for(k=0;k<no;k++)
    if(frame[k]==a[i])
    avail=1;
    if (avail==0)
    {
    frame[j]=a[i];
    j=(j+1)%no;
    count++;
    for(k=0;k<no;k++)
    cout<<frame[k];
}
    cout<<"\n";
}
  cout<<"Page Fault Is "<<count;
}
};
int main()
{
	pagefaultfifo p;
	p.page();
}

