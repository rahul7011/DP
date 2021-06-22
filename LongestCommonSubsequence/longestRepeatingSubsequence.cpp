//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
//longest repeating subsequence

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int m=str.length();
		    int dp[m+1][m+1];
		    for(int i=0;i<m+1;i++)
		    {
		        for(int j=0;j<m+1;j++)
		        {
		            if(i==0 or j==0)
		            {
		                dp[i][j]=0;
		            }
		            else
		            {
		                if(str[i-1]==str[j-1] and i!=j)
		                {
		                    dp[i][j]=dp[i-1][j-1]+1;
		                }
		                else
		                {
		                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		                }
		            }
		        }
		    }
		return dp[m][m];
		}

};
