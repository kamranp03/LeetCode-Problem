class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;

    int solve(int l, int r) {

        // Only one stone -> no more score
        if (l >= r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        // Try every possible split
        for (int i = l; i < r; i++) {

            // Get left and right sums using prefix sum
            int leftSum = prefix[i + 1] - prefix[l];
            int rightSum = prefix[r + 1] - prefix[i + 1];

            if (leftSum < rightSum) {

                // Bob removes right, Alice keeps left
                ans = max(ans,
                          leftSum + solve(l, i));
            }
            else if (leftSum > rightSum) {

                // Bob removes left, Alice keeps right
                ans = max(ans,
                          rightSum + solve(i + 1, r));
            }
            else {

                // Equal -> Alice chooses the better side
                ans = max(ans,
                          leftSum + max(solve(l, i),
                                        solve(i + 1, r)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // Prefix sum
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        // dp[l][r] = maximum score for subarray l...r
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};