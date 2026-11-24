class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxL = 0;
        const long long MAX_CAP = 25200; // max possible gcd * lcm for nums[i] in [1, 10]
        for (int i = 0; i < (int)nums.size(); i++) {
            long long prod = 1;
            int g = 0;
            int l = 1;
            for (int j = i; j < (int)nums.size(); j++) {
                prod *= nums[j];
                if (prod > MAX_CAP) {
                    break;
                }
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                if (prod == 1LL * g * l) {
                    maxL = max(maxL, j - i + 1);
                }
            }
        }
        return maxL;
    }
};