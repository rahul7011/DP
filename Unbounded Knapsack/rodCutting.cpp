//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#
//this is exactly same as unbounded knapsack just the name change
class Solution{
  public:
  int unbounded_knap(int price[],int length[],int N )
  {
      int dp[N+1][N+1];
      for(int i=0;i<N+1;i++)
      {
          //for size of the array
          for(int j=0;j<N+1;j++)
          {
              //for the length of the rod
              if(i==0 or j==0)
              {
                dp[i][j]=0;
              }
              else
              {
                  if(length[i-1]<=j)
                  {
                      dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
                  }
                  else
                  {
                      dp[i][j]=dp[i-1][j];
                  }
              }
          }
      }
      return dp[N][N];
  }
  
    int cutRod(int price[], int n) {
        //creatig a length array
        int length[n];
        for(int i=0;i<n;i++)
        {
            length[i]=i+1;
        }
        
        //same code as unbounded knapsack
        return unbounded_knap(price,length,n);
    }
};
