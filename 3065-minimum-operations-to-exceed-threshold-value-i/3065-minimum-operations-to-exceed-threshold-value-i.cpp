class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int step = 0;

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),
                                                          nums.end());

        while (!pq.empty() && pq.top() < k) {
            step++;
            pq.pop();
        }

        return step;
    }
};