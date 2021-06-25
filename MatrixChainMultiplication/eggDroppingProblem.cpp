//https://leetcode.com/problems/super-egg-drop/submissions/
int dp[10000+3][10000+3];
class Solution {
public:
    int solve(int e,int f)
    {
        if(f==0 or f==1)
        {
            return f;
        }
        if(e==1)
        {
            return f;
        }
        if(dp[e][f]!=-1)
        {
            return dp[e][f];
        }
        int mn=INT_MAX;
        int l=1,h=f;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=solve(e-1,mid-1);  //egg broken check for down floors ofmid
            int right=solve(e,f-mid) ;   
            // not broken check for up floors of mid
            int temp=1+max(left,right);          //store max of both 
            if(left<right){                  
                //since right is more than left and we need more in worst case 
              l=mid+1;                       
                // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            mn=min(mn,temp);               //store minimum attempts
        }
        dp[e][f]=mn;
        return dp[e][f];
    }
    int superEggDrop(int e, int f) {
        memset(dp,-1,sizeof(dp));
        return solve(e,f);
    }
};