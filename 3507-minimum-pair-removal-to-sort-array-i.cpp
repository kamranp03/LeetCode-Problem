class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int idx = 0;

            for (int i = 0; i < nums.size() - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            // reomove pair and add sum
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            count++;
        }

        return count;
    }
};
