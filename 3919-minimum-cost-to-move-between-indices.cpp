class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        vector<int> closest(n);
        
        // Step 1: find closest indices
        for (int i = 0; i < n; i++) {
            if (i == 0) closest[i] = 1;
            else if (i == n - 1) closest[i] = n - 2;
            else {
                int left = abs(nums[i] - nums[i - 1]);
                int right = abs(nums[i] - nums[i + 1]);
                
                if (left <= right) closest[i] = i - 1;
                else closest[i] = i + 1;
            }
        }
        
        // Step 2: forward cost
        vector<long long> forward(n, 0);
        for (int i = 1; i < n; i++) {
            if (closest[i - 1] == i)
                forward[i] = forward[i - 1] + 1;
            else
                forward[i] = forward[i - 1] + (nums[i] - nums[i - 1]);
        }
        
        // Step 3: backward cost
        vector<long long> backward(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            if (closest[i + 1] == i)
                backward[i] = backward[i + 1] + 1;
            else
                backward[i] = backward[i + 1] + (nums[i + 1] - nums[i]);
        }
        
        // Step 4: answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            
            if (l < r)
                ans.push_back(forward[r] - forward[l]);
            else
                ans.push_back(backward[r] - backward[l]);
        }
        
        return ans;
    }
};