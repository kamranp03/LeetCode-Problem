class Solution {
public:
    int n;
    int dp[301][5001];
    int solve(int i, int amount, vector<int>& coins) {
        // 1 way found
        if (amount == 0)
            return 1;

        // out of bount
        if (i == n)
            return 0;

        // invalid
        if (coins[i] > amount)
            return dp[i][amount] = solve(i + 1, amount, coins);

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = solve(i, amount - coins[i], coins);
        int skip = solve(i + 1, amount, coins);

        return dp[i][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();

        memset(dp, -1, sizeof(dp));
        return solve(0, amount, coins);
    }
};