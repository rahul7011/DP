//https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1

//Minimum No. of deletions to make a string palindrome

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        string rs=s;
        reverse(rs.begin(),rs.end());
        int m=s.length();
        int n=rs.length();
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
                    if(s[i-1]==rs[j-1])
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
        int ans=s.length()-dp[m][n];
        return ans;
    } 
};
