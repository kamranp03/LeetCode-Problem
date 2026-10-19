class Solution {
public:
    int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;       // No coins needed
        if (amount < 0) return INT_MAX;  // Invalid amount

        if (dp[amount] != -1)
            return dp[amount];           // Return stored answer

        int mini = INT_MAX;

        for (int coin : coins) {
            int ans = solveMem(coins, amount - coin, dp);

            // Ignore invalid choices
            if (ans != INT_MAX) {
                mini = min(mini, 1 + ans);
            }
        }

        return dp[amount] = mini;         // Store minimum coins
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);   // -1 means not calculated

        int result = solveMem(coins, amount, dp);

        return (result == INT_MAX) ? -1 : result;
    }
};

/*   Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum coins needed to make amount i
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0; // 0 coins needed for amount 0

        // Calculate answer for each amount
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // Return -1 if amount cannot be formed
        return dp[amount] > amount ? -1 : dp[amount];
    }
}; */