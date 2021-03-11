#include<iostream>
#include<map>
#include<iterator>
using namespace std;
typedef struct node* hptr;
hptr heap[500];
struct node 
{
	int freq;
	char data;
	struct node* lc=NULL;
	struct node*rc=NULL;
};
void perculate_up(hptr heap[],int n,hptr temp)
{
	heap[n]=temp;
	int j=n;
	while(j>0 && (heap[j]->freq)<(heap[(j-1)/2]->freq))
	{
		hptr ref=heap[j];
		heap[j]=heap[(j-1)/2];
		heap[(j-1)/2]=ref;
		j=(j-1)/2;
	}
	return ;
}
hptr perculate_down(hptr heap[],int &n)
{
hptr temp=heap[0];
heap[0]=heap[n-1];	
n=n-1;
int j=0;
while((1+2*j)<n && ((heap[j]->freq)>(heap[(1+2*j)]->freq) || (heap[j]->freq)>(heap[(2+2*j)]->freq)))
{
	if((heap[j]->freq)>(heap[(1+2*j)]->freq) && (heap[j]->freq)>(heap[(2+2*j)]->freq))
	{
		if((heap[(1+2*j)]->freq)>(heap[(2+2*j)]->freq))
		{
			hptr ref=heap[j];
			heap[j]=heap[(2+2*j)];
			heap[(2+2*j)]=ref;
			j=2+2*j;
		}
		else
		{
			hptr ref=heap[j];
			heap[j]=heap[(1+2*j)];
			heap[(1+2*j)]=ref;
			j=1+2*j;
		}
	}
	else
	{
		if((heap[j]->freq)>heap[1+2*j]->freq)
		{
			hptr ref=heap[j];
			heap[j]=heap[(1+2*j)];
			heap[(1+2*j)]=ref;
			j=1+2*j;
		}
		else
		{
			hptr ref=heap[j];
			heap[j]=heap[(2+2*j)];
			heap[(2+2*j)]=ref;
			j=2+2*j;
		}
	}
}
return temp;
}
void preorder(hptr root)
{
	if(root!=NULL)
	{
		cout<<root->freq<<" "<<root->data<<endl;
		preorder(root->lc);
		preorder(root->rc);
	}
}
void decode(hptr root,int hf,string st)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->lc==NULL && root->rc==NULL)
	{
	if(hf==0)
	{
		st=st+"0";
	}
	if(hf==1)
	{
		st=st+"1";
	}
	cout<<root->data<<": "<<st<<endl;
	return;	
	}
	if(hf==0)
	{
		st=st+"0";
	}
	if(hf==1)
	{
		st=st+"1";
	}
	decode(root->lc,0,st);
	decode(root->rc,1,st);
}
int main()
{
 	string str;
 	cout<<"enter string: ";
 	cin>>str;
 	map<char,int>mp;
 	for(int i=0;i<str.length();i++)
 	{
 		mp[str[i]]++;
}
	 map<char,int >:: iterator it;
	 int i=0;
	 string st="";
	 for(it=mp.begin();it!=mp.end();it++)
	 {
	 	char ch=it->first;
	 	int f=it->second;
	hptr temp=new struct node;
	temp->data=ch;
	temp->freq=f;
	 	perculate_up(heap,i,temp);
	 	i++;
	 }
	 int n=i;
	 while(n>1)
	 {
	 	hptr t1=perculate_down(heap,n);
	 	hptr t2=perculate_down(heap,n);
	 	hptr t3=new struct node;
	 	t3->data='#';
	 	t3->freq=t1->freq+t2->freq;
	 	t3->lc=t1;
	 	t3->rc=t2;
	 	perculate_up(heap,n,t3);
	 	n++;
	 }
	 hptr root=NULL;
	 root=heap[0];
	 preorder(root);
	 cout<<endl;
	 cout<<"Huffman Decoding: "<<endl;
	decode(root,0,st); 	 
}
