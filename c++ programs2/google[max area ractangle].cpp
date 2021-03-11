#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int maxHist(vector<int>row)
{
	stack<int>result;
	int i=0;
	int n=row.size();
	int hist_area;
	int max_area;
	
	while(i<n)
	{
		if(result.empty()|| row[result.top()]<=row[i])
		{
			result.push(i++);
		}
		else
		{
			int tp=result.top();
			result.pop();
			hist_area=row[tp]*(result.empty()?i:i-result.top()-1);
			if(max_area<hist_area)
			max_area=hist_area;
		}
	}
	while(!result.empty())
	{
		int tp=result.top();
		result.pop();
		hist_area=row[tp]*(result.empty()?i:i-result.top()-1);
		if(max_area<hist_area)
		{
			max_area=hist_area;
		}
	}
	return hist_area;
}
int maxRectangle(vector<vector<int> >&matrix)
{
	int result=maxHist(matrix[0]);	
	for(int i=1;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			if(matrix[i][j]==1)
			matrix[i][j]=matrix[i][j]+matrix[i-1][j];
			
		}
		result=max(result,maxHist(matrix[i]));
	}
	return result;
}
int main()
{
	vector<vector<int> >matrix;
	cout<<"cout<<enter number of rows and columns :";
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		vector<int>v;
		for(int i=0;i<c;i++)
		{
			int a;
			cin>>a;
			v.push_back(a);
		}
		matrix.push_back(v);
	}
//	for(int i=0;i<matrix.size();i++)
//	{
//		for(int j=0;j<matrix[0].size();j++)
//		{
//			cout<<matrix[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int ans=maxRectangle(matrix);
	cout<<ans;
}
/*
4
4
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
*/

