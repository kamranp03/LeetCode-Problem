class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int maxLen = 1;

        for (int j = 0; j < n; j++) {
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }

        return n - maxLen;
    }
};
