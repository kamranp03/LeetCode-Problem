class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        // Sort elements to build consecutive sequences
        sort(nums.begin(), nums.end());

        // dp[x] = longest sequence ending with value x
        unordered_map<int, int> dp;

        int ans = 0;

        for (int x : nums) {

            // Increase current element from x to x+1
            // Ex. 1 -> 2, then current 2 becomes 3
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);

            // Keep current element as x
            // Ex. 1 -> 2, current 2 stays 2
            dp[x] = max(dp[x], dp[x - 1] + 1);

            // Update the maximum sequence length
            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};