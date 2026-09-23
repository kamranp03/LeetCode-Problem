// Approach 1-> Recursion
// class Solution {
// public:
//     int solve(vector<int>& nums, int x, int i, int j) {

//         // X is reduced to zero
//         if(x == 0)
//             return 0;

//         // No elements left
//         if(i > j)
//             return 1e9;

//         int left = 1e9;
//         int right = 1e9;

//         // Remove from left
//         if(nums[i] <= x)
//             left = 1 + solve(nums, x - nums[i], i + 1, j);

//         // Remove from right
//         if(nums[j] <= x)
//             right = 1 + solve(nums, x - nums[j], i, j - 1);

//         // Take minimum of both choices
//         return min(left, right);
//     }

//     int minOperations(vector<int>& nums, int x) {

//         int ans = solve(nums, x, 0, nums.size() - 1);

//         // No valid way found
//         if(ans == 1e9)
//             return -1;

//         return ans;
//     }
// };
// 2. optimal-> 
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        // Total sum of the array
        int total = 0;
        for (int num : nums)
            total += num;

        // Sum of subarray that we want to keep
        int target = total - x;

        // If target is negative, impossible
        if (target < 0)
            return -1;

        // If target is 0, remove the whole array
        if (target == 0)
            return nums.size();

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        // Find longest subarray with sum = target
        for (int right = 0; right < nums.size(); right++) {

            // Add current element
            sum += nums[right];

            // Shrink window if sum becomes too large
            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // Check if current window has target sum
            if (sum == target)
                maxLen = max(maxLen, right - left + 1);
        }

        // Operations = elements removed from both ends
        if (maxLen == -1)
            return -1;

        return nums.size() - maxLen;
    }
};