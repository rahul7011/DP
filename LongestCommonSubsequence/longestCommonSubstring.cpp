//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(s1[i-1]==s2[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
            }
        }
        //finding the longest one
        int mn=INT_MIN;
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                mn=max(mn,dp[i][j]);
            }
        }
        return mn;
    }
};