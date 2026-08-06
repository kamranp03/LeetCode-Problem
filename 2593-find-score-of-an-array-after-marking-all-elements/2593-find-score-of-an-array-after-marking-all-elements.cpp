class Solution {
public:
    long long findScore(vector<int>& nums) {

        long long sum = 0;
        int n = nums.size();

        vector<bool> vis(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while (!pq.empty()) {

            int ele = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if (vis[idx])
                continue;

            sum += ele;

            vis[idx] = true;

            if (idx > 0)
                vis[idx - 1] = true;

            if (idx < n - 1)
                vis[idx + 1] = true;
        }

        return sum;
    }
};