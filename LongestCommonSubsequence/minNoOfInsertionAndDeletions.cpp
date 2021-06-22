//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1


class Solution
{

public:
	int minOperations(string str1, string str2)
	{
		int m = str1.length();
		int n = str2.length();
		int dp[m + 1][n + 1];
		for (int i = 0; i < m + 1; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				if (i == 0 or j == 0)
				{
					dp[i][j] = 0;
				}
				else
				{
					if (str1[i - 1] == str2[j - 1])
					{
						dp[i][j] = 1 + dp[i - 1][j - 1];
					}
					else
					{
						dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
					}
				}
			}
		}
		int insertion = str2.length() - dp[m][n];
		int deletion = str1.length() - dp[m][n];
		return insertion + deletion;
	}
};