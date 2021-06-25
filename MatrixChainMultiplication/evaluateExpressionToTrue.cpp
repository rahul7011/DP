//https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
//Note:-GFG Updated it's constraint and looking for an iterative approach / complete matrix approach.

//memoized code

// unordered_map<string,int>mp;
// class Solution{
// public:
// int solve(string s,int i,int j,bool is_true)
// {
//     if(i>j)
//     {
//         return false;
//     }
//     if(i==j)
//     {
//         if(is_true==true)
//         {
//             return s[i]=='T';
//         }
//         else
//         {
//             return s[i]=='F';
//         }
//     }
//     //format i+" "+j+" "+is_true
//     string blank="";
//     string temp=to_string(i);
//     temp.append(blank);
//     temp.append(to_string(j));
//     temp.append(blank);
//     temp.append(to_string(is_true));
//     if(mp.find(temp)!=mp.end())
//     {
//         return mp[temp];
//     }
//     int ans=0;
//     for(int k=i+1;k<j;k+=2)
//     {
//         int lt=solve(s,i,k-1,true);
//         int lf=solve(s,i,k-1,false);
//         int rt=solve(s,k+1,j,true);
//         int rf=solve(s,k+1,j,false);
//         //symbols &,| and ^
//         if(s[k]=='&')
//         {
//             if(is_true==true)
//             {
//                 ans+=lt*rt;
//             }
//             else
//             {
//                 ans+=lf*rf+lf*rt+lt*rf;
//             }
//         }
//         else if(s[k]=='|')
//         {
//             if(is_true==true)
//             {
//                 ans+=lf*rt+lt*rf+lt*rt;
//             }
//             else
//             {
//                 ans+=lf*rf;
//             }
//         }
//         else if(s[k]=='^')
//         {
//             if(is_true==true)
//             {
//                 ans+=lt*rf+rt*lf;
//             }
//             else
//             {
//                 ans+=lt*rt+lf*rf;
//             }
//         }
//     }
//     mp[temp]=ans;
//     return mp[temp];
// }
//     int countWays(int N, string S){
//         mp.clear();
//         return solve(S,0,N-1,true);
//     }
// };

//bottom up approach

//since 3 variables are changing
long long dp[203][203][2];
int mod=1003;
class Solution
{
public:
    long long solve(string s, long long i, long long j, bool is_true)
    {
        if (i > j)
        {
            return false;
        }
        if (i == j)
        {
            if (is_true == true)
            {
                return s[i] == 'T';
            }
            else
            {
                return s[i] == 'F';
            }
        }
        //format i+" "+j+" "+is_true
        if (dp[i][j][is_true] != -1)
        {
            return dp[i][j][is_true];
        }
        long long ans = 0;
        for (long long k = i + 1; k < j; k += 2)
        {
            long long lt, lf, rt, rf;
            if (dp[i][k - 1][true] == -1)
            {
                lt = solve(s, i, k - 1, true)%mod;
            }
            else
            {
                lt = dp[i][k - 1][true];
            }
            if (dp[i][k - 1][false] == -1)
            {
                lf = solve(s, i, k - 1, false)%mod;
            }
            else
            {
                lf = dp[i][k - 1][false];
            }
            if (dp[k + 1][j][true] == -1)
            {
                rt = solve(s, k + 1, j, true)%mod;
            }
            else
            {
                rt = dp[k + 1][j][true];
            }
            if (dp[k + 1][j][false] == -1)
            {
                rf = solve(s, k + 1, j, false)%mod;
            }
            else
            {
                rf = dp[k + 1][j][false];
            }
            //symbols &,| and ^
            if (s[k] == '&')
            {
                if (is_true == true)
                {
                    ans += (lt * rt)%mod%mod;
                }
                else
                {
                    ans += ((lf * rf)%mod + (lf * rt)%mod + (lt * rf)%mod)%mod%mod;
                }
            }
            else if (s[k] == '|')
            {
                if (is_true == true)
                {
                    ans += ((lf * rt)%mod + (lt * rf)%mod + (lt * rt)%mod)%mod%mod;
                }
                else
                {
                    ans += (lf * rf)%mod%mod;
                }
            }
            else if (s[k] == '^')
            {
                if (is_true == true)
                {
                    ans += ((lt * rf)%mod + (rt * lf)%mod)%mod%mod;
                }
                else
                {
                    ans += ((lt * rt)%mod + (lf * rf)%mod)%mod%mod;
                }
            }
        }
        dp[i][j][is_true] = ans;
        return dp[i][j][is_true];
    }
    long long countWays(long long N, string S)
    {
        memset(dp, -1, sizeof(dp));
        return solve(S, 0, N - 1, true);
    }
};