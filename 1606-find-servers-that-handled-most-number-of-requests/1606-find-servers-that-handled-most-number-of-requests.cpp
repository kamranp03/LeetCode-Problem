class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Min-heap to store busy servers: pair of {free_time, server_id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_servers;
        
        // Set to store currently available server IDs
        set<int> available_servers;
        for (int i = 0; i < k; ++i) {
            available_servers.insert(i);
        }
        
        vector<int> request_count(k, 0);
        int max_requests = 0;
        
        for (int i = 0; i < arrival.size(); ++i) {
            long long curr_time = arrival[i];
            
            // 1. Free up servers whose tasks have finished by curr_time
            while (!busy_servers.empty() && busy_servers.top().first <= curr_time) {
                available_servers.insert(busy_servers.top().second);
                busy_servers.pop();
            }
            
            // 2. If no servers are available, drop the request
            if (available_servers.empty()) {
                continue;
            }
            
            // 3. Find the first available server >= (i % k)
            int target = i % k;
            auto it = available_servers.lower_bound(target);
            
            // If no server >= target is found, wrap around to the beginning of the set
            if (it == available_servers.end()) {
                it = available_servers.begin();
            }
            
            int assigned_server = *it;
            
            // Assign the request to this server
            available_servers.erase(it);
            busy_servers.push({curr_time + load[i], assigned_server});
            
            request_count[assigned_server]++;
            max_requests = max(max_requests, request_count[assigned_server]);
        }
        
        // 4. Collect all servers that handled the maximum number of requests
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};