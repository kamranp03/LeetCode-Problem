// X-Or 1^1 / 0^0 = 0 & 1^0 / 0^1 = 1

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0; // xor
        int len = nums.size();

        bool nonZero = false;

        for (int& num : nums) {
            nonZero |= num > 0;
            total ^= num;
        }

        if (total != 0)
            return len;

        if (nonZero)
            return len - 1;

        return 0;
    }
};