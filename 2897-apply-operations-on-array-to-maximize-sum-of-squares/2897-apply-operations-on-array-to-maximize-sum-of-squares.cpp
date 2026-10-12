class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);

        // count all set(1) bitts on all position 
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) // check set or not
                    count[i]++;
            }
        }

        long long res = 0;

    // generate k numbers by using that bits and add square of them in res;
        while (k--) {
            long long curr = 0;
            for (int i = 0; i < 32; i++) {
                if (count[i] > 0) {
                    count[i]--;
                    curr = curr | (1 << i); // set bit
                }
            }

            res = (res + (curr * curr)) % MOD;
        }

        return res;
    }
};