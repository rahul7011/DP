//https://leetcode.com/problems/shortest-common-supersequence/
//printing shortestCommonSupersequence (SCS)

class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int m=X.length();
        int n=Y.length();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(X[i-1]==Y[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        //since we have the lcs now we just have to find the string lcs
        int i=m;
        int j=n;
        string s;
        while(i>0 and j>0)
        {
            if(X[i-1]==Y[j-1])
            {
                s.push_back(X[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    s.push_back(X[i-1]);
                    i--;
                }
                else
                {
                    s.push_back(Y[j-1]);
                    j--;
                }
            }
        }
        // if s1 characters are still left
        while(i>0)
        {
            s.push_back(X[i-1]);
            i--;
        }
        //if s2 characters are still left
        while(j>0)
        {
            s.push_back(Y[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};