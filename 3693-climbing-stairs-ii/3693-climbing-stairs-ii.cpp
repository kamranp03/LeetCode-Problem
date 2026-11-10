class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int min_cost = INT_MAX;
            // jumps  i - 1, i - 2, i - 3
            for (int k = 1; k <= 3; k++) {
                if (i - k >= 0) {
                    // dp[i-k] = minimum cost to reach previous stair
                    // costs[i-1] = cost of current stair
                    // k*k = extra cost based on jump length (j-i)^2
                    int jump_cost = dp[i - k] + costs[i - 1] + (k * k);
                    min_cost = min(min_cost, jump_cost);
                }
            }
            dp[i] = min_cost;
        }
        return dp[n];
    }
};