#include<iostream>
#include<cstring>
#include<set>
#include<queue>
using namespace std;
bool isValidString(string str)
{
    int cnt=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
            cnt++;
        if(str[i]==')')
            cnt--;
        if(cnt<0)
            return false;
    }
    return (cnt==0);
}
bool isParenthesis(char str)
{
        return (str=='(' ||str==')');
    }
void removeInvalidParenthesis(string str)
{
    string temp;
    set<string>visit;
    queue<string>q;
    q.push(str);
    bool level;
    visit.insert(str);
    while(!q.empty())
    {
        str=q.front();
        q.pop();
        if(isValidString(str))
        {
            cout<<str<<"     ";
            level=true;
        }
        else if(!isValidString(str))
        {

        for(int i=0;i<str.length();i++)
            {
                if(! isParenthesis(str[i]))
                    continue;
                temp=str.substr(0,i)+str.substr(i+1);
                if(visit.find(temp)==visit.end())
                {
                    visit.insert(temp);
                    q.push(temp);
                }
            }
        }
    }
}
int main()
{
    string str="()())()";
    removeInvalidParenthesis(str);
}
