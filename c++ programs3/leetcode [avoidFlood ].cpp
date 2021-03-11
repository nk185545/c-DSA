 #include<iostream>
 #include<map>
 #include<vector>
 #include<iterator>
 using namespace std ;
 vector<int> avoidFlood(vector<int>& rains) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<rains.size();i++)
        {
//            cout<<mp.size()<<" ";
//            map<int,int> :: iterator it1 ;
//                for(it1=mp.begin();it1!=mp.end();it1++)
//                {
//                    cout<<it1->first<<" : "<<it1->second<<" @@@@@ ";
//                }
//                cout<<endl;
            if(mp[rains[i]]==0 && rains[i]!=0)
            {
                mp[rains[i]]++;
                ans.push_back(-1);
            }
            else if(rains[i]==0 && mp.size()>0)
            {
            	//cout<<"ELSEIF ";
                int a=-1000000 ;
                int cnt=0 ;
                map<int,int> :: iterator it ;
                for(it=mp.begin();it!=mp.end();it++)
                {
                    if(cnt< it->second)
                    {
                        cnt = it->second ;
                        a= it->first ;
                    }
                }
                if(a!=-1000000)
                {
                	ans.push_back(a);
	                mp[a]--;
	                if(mp[a]==0)
	                {
	                //	cout<<"ERASE";
	                    mp.erase(a) ;
	                }
	                
				}
				 cout<<mp.size()<<" ";
                
            }
           else if(mp[rains[i]]>0)
            {
                vector<int>res;
                return res;
            }
           else if(rains[i]==0)
            {
                ans.push_back(1);
            }
        }
         return ans;
    }
    int main()
    {
    	vector<int> v ;
    	v.push_back(69);
    	v.push_back(0);
    	v.push_back(0);
    	v.push_back(0);
    	v.push_back(69);
    	vector<int> ans = avoidFlood(v) ;
    	cout<<endl;
    	for(int i=0;i<ans.size();i++)
    	{
    		cout<<ans[i]<<" ";
		}
}
