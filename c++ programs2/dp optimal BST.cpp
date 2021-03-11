 #include<iostream>
 using namespace std;
 float OBST(float sum[100][100],int keys[],int n)
{
   float cost[n+1][n+1];	
	for(int i=1;i<=n;i++)
	{
		cost[i][i]=sum[i][i];
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=l+i-1;
			cost[i][j]=INT_MAX;
			for(int k=i;k<=j;k++)
			{
				float t=cost[i][k-1]+cost[k+1][j]+sum[i][j];
				if(t<cost[i][j])
				{
					cost[i][j]=t;	
				}
			}
		}
		
	}
   return cost[1][n];
}	

 void probSum(float arr[],int keys[],int n)
 {
 	float sum[100][100];
   for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=n;j++)
	 	if(i==j)
	 	sum[i][j]=arr[i-1];
	 }
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=n;j++)
	 	{
	 		if(i<j)
	 	{
	 		sum[i][j]=arr[j-1]+sum[i][j-1];
		 }
		 if(i>j)
		 {
		 	sum[i][j]=0;
		 }
	 }
 }
//  for(int i=1;i<=n;i++)
//	 {
//	 	for(int j=1;j<=n;j++)
//	 	{
//	 	  cout<<sum[i][j]<<"   ";
//	    }
//	  cout<<endl;
//     }
     float ans=OBST(sum,keys,n);
    cout<<ans;
}

 int main()
 {
 	int n;
 	cout<<"enter number of nodes: ";
 	cin>>n;
 	float arr[n];
 	cout<<"enter frequencies ";
 	for(int i=0;i<n;i++)
 	{
 		cin>>arr[i];
	}
	cout<<"enter nodes/keys ";
	int keys[n];
	for(int i=0;i<n;i++)
 	{
 		cin>>keys[i];
	}
	probSum(arr,keys,n);
	return 0;
 }
