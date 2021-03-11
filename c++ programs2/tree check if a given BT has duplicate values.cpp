#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
btptr newNode(int data )
 {
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = data ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		return temp ;

 }
void BThasDuplicateValues(btptr t,vector<int>&v)
{
    if(t==NULL)
    {
        return;
    }
   v.push_back(t->data);
   BThasDuplicateValues(t->lc,v);
   BThasDuplicateValues(t->rc,v);
}
int main()
{	btptr root = newNode(10);
    root->lc        = newNode(8);
    root->rc       = newNode(2);
    root->rc->lc  = newNode(2);
    root->lc->rc = newNode(5);
    root->rc->rc = newNode(7);
    root->lc->lc=newNode(3);
    root->lc->lc->lc=newNode(4);
    vector<int>v;
    BThasDuplicateValues(root,v);
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]==v[i+1])
        {
            cout<<"there is duplicate elments in tree :  "<<v[i];
            break;
        }
        else{cnt++;}
    }
    if(cnt==v.size()-1)
    {
        cout<<"no duplicate elements in tree: ";    }
    return 0;
}
