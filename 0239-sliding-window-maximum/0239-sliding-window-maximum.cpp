class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq; // stores indices
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are outside current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all smaller elements from back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // First window forms when i = k-1
            if (i >= k - 1) {
                // Front of deque always contains
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};