class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(vector<int>& nums, int i, int p) {
        if (i >= n)
            return 0; // out of bound

        // if p != -1 then we acces dp 
        if (p != -1 && dp[i][p] != -1)
            return dp[i][p];

        int take = 0;
        // for take prev is less or perev is not -1 
        if (p == -1 || nums[i] > nums[p])
            take = 1 + solve(nums, i + 1, i);
        int skip = solve(nums, i + 1, p);

        // p != -1 then we store in dp
        if (p != -1)
            dp[i][p] = max(take, skip);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};