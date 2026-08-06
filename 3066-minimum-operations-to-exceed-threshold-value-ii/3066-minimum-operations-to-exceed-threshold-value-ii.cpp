class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int step = 0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int x : nums)
            pq.push(x);

        while (pq.size() >= 2 && pq.top() < k) {

            long long min1 = pq.top();
            pq.pop();

            long long min2 = pq.top();
            pq.pop();

            long long newE = min1 * 2 + min2;

            pq.push(newE);

            step++;
        }

        return step;
    }
};