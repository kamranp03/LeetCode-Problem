class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by timestamp
        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });

        // Store query with original index
        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0, active = 0;

        for(auto [time, idx] : q) {

            // Add logs up to query time
            while(right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];

                if(freq[server] == 0)
                    active++;

                freq[server]++;
                right++;
            }

            // Remove logs outside the time window
            while(left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                freq[server]--;

                if(freq[server] == 0)
                    active--;

                left++;
            }

            // Count servers with zero requests
            ans[idx] = n - active;
        }

        return ans;
    }
};

// 1. Sort logs and queries by timestamp.
// 2. Add logs whose time <= current query.
// 3. Remove logs whose time < query - x.
// 4. Answer = total servers - active servers.