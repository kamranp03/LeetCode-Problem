class Solution {
public:
    int n;
    int dp[201][20001];
    bool solve(vector<int>& nums, int i, int x) {
        if (x == 0)
            return true;

        if (i >= n)
            return false;
        if (dp[i][x] != -1)
            return dp[i][x];
        bool take = 0;
        if (x >= nums[i])
            take = solve(nums, i + 1, x - nums[i]);

        bool skip = solve(nums, i + 1, x);

        return dp[i][x] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        int S = accumulate(nums.begin(), nums.end(), 0);

        // toatal sum is odd (means not devided)
        if (S % 2 != 0)
            return false;

        // if one subset found exact half of total (tats means another is always half )
        int x = S / 2;

        return solve(nums, 0, x);
    }
};