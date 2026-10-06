class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, res = 0;

        while (r < nums.size() - 1) {
            int maxPos = 0;

            for (int i = l; i <= r; i++) {
                maxPos = max(maxPos, i + nums[i]);
            }

            l = r + 1;
            r = maxPos;
            res++;
        }
        return res;
    }
};