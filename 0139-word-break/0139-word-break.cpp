class Solution {
public:
    int n;
    unordered_set<string> st; // set for store all dict words to acces in o(1)
    int t[301];

    bool solve(int idx, string &s)
    {
        // out of bound means last is valid break
        if(idx==n) return 1;

        // if current string found in set
        if(st.find(s) != st.end()) return 1;

        if(t[idx] !=-1) return t[idx];

        // try break words
        for(int l=1;l<=n;l++)
        {
            string tmp= s.substr(idx, l); // broken string
            // check broken string in in dict and , next remain also in dict
            if(st.find(tmp) != st.end() && solve(idx+l, s))
                return t[idx]= 1;
        }

        // last not valid broke
        return t[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n= s.length();
        memset(t,-1,sizeof(t));

        for(string w: wordDict)
            st.insert(w);

        return solve(0,s);
    }
};
/*
Tabulation 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st;

        for (string w : wordDict)
            st.insert(w);

        vector<bool> dp(n + 1, false);

        dp[n] = true; // Empty string is valid

        // Start from the end
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int len = 1; len <= n - idx; len++) {
                string tmp = s.substr(idx, len);

                // Word exists and remaining string is valid
                if (st.find(tmp) != st.end() && dp[idx + len]) {
                    dp[idx] = true;
                    break;
                }
            }
        }

        return dp[0]; // Can the complete string be broken?
    }
}; */