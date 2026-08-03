class Solution {
public:
    vector<int> dp;

    int solve(int i, int n, vector<int>& nums) {

        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MIN;

        // Take 1 stone
        int take1 = nums[i] - solve(i + 1, n, nums);
        ans = max(ans, take1);

        // Take 2 stones
        if (i + 1 < n) {
            int take2 = nums[i] + nums[i + 1] - solve(i + 2, n, nums);
            ans = max(ans, take2);
        }

        // Take 3 stones
        if (i + 2 < n) {
            int take3 =
                nums[i] + nums[i + 1] + nums[i + 2] - solve(i + 3, n, nums);
            ans = max(ans, take3);
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        dp.assign(n, -1);

        int ans = solve(0, n, stoneValue);

        if (ans > 0)
            return "Alice";
        else if (ans < 0)
            return "Bob";

        return "Tie";
    }
};