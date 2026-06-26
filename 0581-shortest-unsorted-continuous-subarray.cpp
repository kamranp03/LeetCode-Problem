class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        // Step 1: find first violation from left
        while (l < n - 1 && nums[l] <= nums[l + 1]) l++;

        // already sorted
        if (l == n - 1) return 0;

        // Step 2: find first violation from right
        while (r > 0 && nums[r] >= nums[r - 1]) r--;

        // Step 3: find min & max in [l, r]
        int subMin = INT_MAX, subMax = INT_MIN;
        for (int i = l; i <= r; i++) {
            subMin = min(subMin, nums[i]);
            subMax = max(subMax, nums[i]);
        }

        // Step 4: expand left
        while (l > 0 && nums[l - 1] > subMin) l--;

        // Step 5: expand right
        while (r < n - 1 && nums[r + 1] < subMax) r++;

        return r - l + 1;
    }
};