//https://www.interviewbit.com/problems/scramble-string/#



unordered_map<string,bool>mp;
bool solve(string A,string B)
{
    if(A.compare(B)==0)
    {
        return true;
    }
    if(A.length()<=1)
    {
        return false;
    }
    //forming key
    string key=A;
    key.append(" ");
    key.append(B);
    if(mp.find(key)!=mp.end())
    return mp[key];
    int n=A.length();
    bool flag=false;
    for(int i=1;i<n;i++)
    {
        //swap and non-swap
        if((solve(A.substr(0,i),B.substr(n-i,i)) && solve(A.substr(i,n-i),B.substr(0,n-i))) || ((solve(A.substr(0,i),B.substr(0,i)) && solve(A.substr(i,n-i),B.substr(i,n-i)))))
        {
            flag=true;
            break;
        }
    }
    mp[key]=flag;
    return mp[key];
}
int Solution::isScramble(const string A, const string B) {
    if (A.length() != B.length())
        return 0;
    else
        return solve(A, B);
    return 0;
}