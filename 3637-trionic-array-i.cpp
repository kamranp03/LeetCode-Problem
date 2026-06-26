class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;

        // 1️.strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        if (i == 0) return false;  // no first increase

        // 2️. strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }

    
        if (i == n - 1) return false;

        // 3 strictly increasing
        bool thirdIncrease = false;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            thirdIncrease = true;
            i++;
        }

        return thirdIncrease && i == n - 1;
    }
};
