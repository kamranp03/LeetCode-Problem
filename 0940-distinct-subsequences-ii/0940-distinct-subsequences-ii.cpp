class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        long long dp = 1;
        vector<long long> last(26, 0);

        for (char c : s) {
            long long newDp = (2 * dp) % MOD;

            // Remove duplicates
            newDp = (newDp - last[c - 'a'] + MOD) % MOD;

            last[c - 'a'] = dp;
            dp = newDp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};