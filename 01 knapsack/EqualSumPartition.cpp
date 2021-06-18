//https://leetcode.com/problems/partition-equal-subset-sum/



class Solution {
public:
    bool knapsack(vector<int>&nums,int n,int sum)
    {
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
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
                    if(nums[i-1]<=j)
                    {
                        dp[i][j]=(dp[i-1][j-nums[i-1]] or dp[i-1][j]);
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==0)
        {
            return knapsack(nums,n,sum/2);
        }
        else
        {
            return false;
        }
    }
};