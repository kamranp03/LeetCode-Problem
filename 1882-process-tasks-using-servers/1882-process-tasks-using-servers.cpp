class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        // Free heap: {weight, server index}
        // Select server with minimum weight, then minimum index
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> free;

        // Busy heap: {free time, weight, server index}
        // Select server that becomes free earliest
        priority_queue<tuple<long long,int,int>,
                       vector<tuple<long long,int,int>>,
                       greater<tuple<long long,int,int>>> busy;

        // Initially, all servers are free
        for (int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0;

        // Process tasks in their given order
        for (int i = 0; i < m; i++) {

            // Current time cannot be earlier than task arrival
            time = max(time, (long long)i);

            // Move all completed servers back to free heap
            while (!busy.empty() && get<0>(busy.top()) <= time) {

                auto [endTime, wt, idx] = busy.top();
                busy.pop();

                free.push({wt, idx});
            }

            // If no server is free, wait for earliest server
            if (free.empty()) {

                // Move time to the earliest finishing time
                time = get<0>(busy.top());

                // Release all servers available at this time
                while (!busy.empty() && get<0>(busy.top()) <= time) {

                    auto [endTime, wt, idx] = busy.top();
                    busy.pop();

                    free.push({wt, idx});
                }
            }

            // Select the best available server
            auto [wt, idx] = free.top();
            free.pop();

            // Store the assigned server index
            ans[i] = idx;

            // Server becomes free after completing this task
            busy.push({time + tasks[i], wt, idx});
        }

        return ans;
    }
};