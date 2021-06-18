//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution
{
public:
    bool isSubsetSum(int N, int arr[], int sum)
    {
        bool dp[N + 1][sum + 1];
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0 or j == 0)
                {
                    if (i == 0)
                        dp[i][j] = false;
                    if (j == 0)
                        dp[i][j] = true;
                }
                else
                {
                    if (arr[i - 1] <= sum)
                    {
                        dp[i][j] = (dp[i - 1][j - arr[i - 1]] or dp[i - 1][j]);
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[N][sum];
    }
};