//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#

class Solution{

  public:
  vector<int>subsetSum(int arr[],int n,long long range)
  {
      bool dp[n+1][range+1];
      for(int i=0;i<n+1;i++)
      {
          for(int j=0;j<range+1;j++)
          {
              if(i==0 or j==0)
              {
                  if(i==0)
                  {
                      dp[i][j]=false;
                  }
                  if(j==0)
                  {
                      dp[i][j]=true;
                  }
              }
              else
              {
                  if(arr[i-1]<=j)
                  {
                      dp[i][j]=dp[i-1][j-arr[i-1]] or dp[i-1][j];
                  }
                  else
                  {
                      dp[i][j]=dp[i-1][j];
                  }
              }
          }
      }
      vector<int>v;
      for(int i=0;i<=range/2;i++)
      {
          if(dp[n][i]==true)
          v.push_back(i);
      }
      return v;
  }
  
	int minDifference(int arr[], int n)  { 
	    int range=0;
	    for(int i=0;i<n;i++)
	    {
	        range+=arr[i];
	    }
	    vector<int>v=subsetSum(arr,n,range);
	    //finding the minimum
	    int mn=INT_MAX;
	    for(int i=0;i<v.size();i++)
	    {
	        mn=min(mn,range-2*v[i]);
	    }
	    return mn;
	} 
};