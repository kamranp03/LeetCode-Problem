class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }

        sort(even.begin(), even.end());
        sort(odd.rbegin(), odd.rend());

        int i = 0, j = 0, idx = 0;

        while (i < even.size() && j < odd.size()) {
            nums[idx++] = even[i++];
            nums[idx++] = odd[j++];
        }

        // Remaining even element(s)
        while (i < even.size()) {
            nums[idx++] = even[i++];
        }

        return nums;
    }
};