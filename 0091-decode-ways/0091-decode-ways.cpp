// memoization tc- o(2^n)

//     int dp[101]; // max size in co ntraint 100 s
//     int solve(int i, string& s, int n)
//     {
//         if(dp[i] != -1) return dp[i];
//         if(i==n)
//         {
//             return dp[i]=1; // one way found
//         }

//         if(s[i]=='0') return dp[i]=0;

//         int res= solve(i+1,s,n); // only one char take

//         if(i+1<n){
//             if(s[i]=='1' || (s[i]=='2' && s[i+1] <= '6'))
//                 res+= solve(i+2,s,n); // take i and i+1
//         }
//         return dp[i]=res;
//     }
//     int numDecodings(string s) {
//         int n= s.length();
//         memset(dp,-1,sizeof(dp));
//         return solve(0,s,n);
//     }
// };

// Tabulation / Botom Up -> Tc o(n)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else {
                dp[i] = dp[i + 1]; // solve(i+1);

                if (i + 1 < n) {
                    if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                        dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};