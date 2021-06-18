//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution{

	public:
int perfectSum(int nums[], int n,int target)
	{
	    long long mod=1000000007;
        int dp[n+1][target+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<target+1;j++)
            {
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
                    if(nums[i-1]<=j)
                    {
                        dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-nums[i-1]]%mod)%mod;
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][target];
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}