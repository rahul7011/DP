//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
int dp[503][503];
class Solution{
public:
bool is_palindrome(string s,int i,int j)
{
    if(i>=j)
    {
        return true;
    }
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


    int solve(string s,int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(is_palindrome(s,i,j))
        {
            return 0;   
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int left,right,temp;
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(dp[i][k]!=-1)
            {
                left=dp[i][k];
            }
            else
            {
                left=solve(s,i,k);
            }
            if(dp[k+1][j]!=-1)
            {
                right=dp[k+1][j];
            }
            else
            {
                right=solve(s,k+1,j);
            }
            temp=left+right+1;
            mn=min(mn,temp);
        }
        dp[i][j]=mn;
        return dp[i][j];
    }
    
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
       return solve(str,0,str.length()-1);
    }
};