class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            int found = -1;

            for (int x = 0; x <= n; x++) {
                if ((x | (x + 1)) == n) {
                    found = x;
                    break;
                }
            }

            ans.push_back(found);
        }
        return ans;
    }
};
