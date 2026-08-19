class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int i = 0; // even index
        int j = 1;  // odd index

        for (int x : nums) {
            if (x % 2 == 0) {
                res[i] = x;
                i += 2;
            } else {
                res[j] = x;
                j += 2;
            }
        }

        return res;
    }
};