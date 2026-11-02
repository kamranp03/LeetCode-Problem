class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int diff = 0;
        int n = nums.size();
        int mid = n / 2;
        // we want a element till that every ele can reach, since it will get
        // minimum moves to equalize array
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            diff += abs(nums[mid] - nums[i]);
        }

        return diff;
    }
};