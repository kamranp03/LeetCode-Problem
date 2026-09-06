class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s,string& t, int idx, int tidx)
    {
        //t complete
        if(tidx==t.length())
        {
            return 1;
        }
        //s finished
        if(idx==s.length())
        {
            return 0;
        }
        if(dp[idx][tidx] !=-1)
        {
            return dp[idx][tidx];
        }
        int ans=0;

        //take
        if(s[idx]==t[tidx])
        {
            ans+=solve(s,t,idx+1,tidx+1);
        }
        //not take
        ans+=solve(s,t,idx+1,tidx);

        return dp[idx][tidx]=ans;

    }
    int numDistinct(string s, string t) {
       int n=s.length();
       int m=t.length();

       dp.assign(n,vector<int>(m,-1));
       return solve(s,t,0,0);
    }
};