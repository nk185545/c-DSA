#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int j=n-1;
        sort(nums.begin(),nums.end());
        vector<int>v;
        int i=0;
        while(i<j)
        {
         if((nums[i]+nums[j])==target)
         {
             v.push_back(i);
             v.push_back(j);
             cout<<v[i]<<" "<<v[j];
             break;
         }
           else if((nums[i]+nums[j])>target)
         {
            j--;
         }
           else if((nums[i]+nums[j])<target)
         {
             i++;
         }
        }
        return v; 
    }
    int main()
    {
    	vector<int>v;
    	int n;
    	cin>>n;
    	int x,target;
    	cin>>target;
    	for(int i=0;i<n;i++)
    	{
    		cin>>x;
    		v.push_back(x);
		}
		twoSum(v,target);
		return 0;
	}
