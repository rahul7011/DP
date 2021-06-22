#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

#define nl cout << "\n"
#define ll long long int
#define ull unsigned long long int
#define MAX 10000

//write your function here
string lcs(string s1, string s2, int m, int n)
{
    //calculating lcs
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
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    //now forming the string
    string ans;
    int i = m;
    int j = n;
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    reverse(ans.begin(),ans.end());
    return ans;

}

int32_t main()
{
    IOS;

    //https://www.geeksforgeeks.org/printing-longest-common-subsequence/

    // s1=acbcf
    // s2=abcdaf
    // output=abcf 
      
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2, s1.length(), s2.length());
}