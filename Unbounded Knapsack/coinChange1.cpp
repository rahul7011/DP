//https://practice.geeksforgeeks.org/problems/coin-change2448/1
//Unbounded Knapsack version of CountOFSubsetWithGivenSum
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       
        long long dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
            //size of the array
            for(int j=0;j<n+1;j++)
            {
                //to make N cents
                if(i==0 or j==0)
                {
                    if(i==0)
                    {
                        dp[i][j]=0;
                    }
                    if(j==0)
                    {
                        dp[i][j]=1;
                    }
                }
                else
                {
                    if(S[i-1]<=j)
                    {
                        dp[i][j]=dp[i][j-S[i-1]]+dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};