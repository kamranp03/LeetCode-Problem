class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> exists(101);

        for (int n : nums)
            exists[n] = true;

        int n = k;
        while (n < 101) {
            if (!exists[n])
                return n;
            n += k;
        }

        return n;
    }
};