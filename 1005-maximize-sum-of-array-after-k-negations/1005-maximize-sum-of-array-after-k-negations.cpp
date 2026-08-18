class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        // Sort so negative numbers come first
        sort(nums.begin(), nums.end());

        int i = 0;

        // Flip negative numbers first
        while (k > 0 && i < nums.size() && nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
            i++;
        }

        // If K is still left, flip the smallest absolute value
        if (k % 2 == 1) {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }

        // Calculate sum
        int sum = 0;
        for (int x : nums)
            sum += x;

        return sum;
    }
};