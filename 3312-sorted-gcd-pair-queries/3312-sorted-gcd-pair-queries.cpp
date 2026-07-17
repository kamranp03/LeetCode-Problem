class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        // frequency of each number
        vector<int> freq(mx + 1, 0);

        for (int num : nums) {
            freq[num]++;
        }

        vector<long long> gcdCnt(mx + 1, 0);

        for (int i = mx; i >= 1; i--) {
            long long cnt = 0;

            // count numbers divisible by i
            for (int j = i; j <= mx; j += i) {
                cnt += freq[j];
            }

            // total possible pairs
            gcdCnt[i] = cnt * (cnt - 1) / 2;

            // remove pairs already counted by multiples
            for (int j = 2 * i; j <= mx; j += i) {
                gcdCnt[i] -= gcdCnt[j];
            }
        }

        // prefix sum
        for (int i = 1; i <= mx; i++) {
            gcdCnt[i] += gcdCnt[i - 1];
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            ans[i] = upper_bound(gcdCnt.begin(), gcdCnt.end(), queries[i]) -
                     gcdCnt.begin();
        }

        return ans;
    }
};