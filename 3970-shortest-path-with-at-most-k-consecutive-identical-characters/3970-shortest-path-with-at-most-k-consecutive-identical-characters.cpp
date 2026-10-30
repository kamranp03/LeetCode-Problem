class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Min heap: {weight, node, consecutive count}
        priority_queue<array<int, 3>,
                       vector<array<int, 3>>,
                       greater<array<int, 3>>> pq;

        // dist[node][count] = minimum cost to reach this state
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        // Start from node 0 with count 1
        pq.push({0, 0, 1});
        dist[0][1] = 0;

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int wt = curr[0];
            int u = curr[1];
            int count = curr[2];

            // Skip outdated states
            if (wt > dist[u][count]) continue;

            // Destination reached
            if (u == n - 1) return wt;

            // Explore all neighbours
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                // Update consecutive count
                int next_count = 1;

                if (labels[u] == labels[v]) {
                    next_count = count + 1;
                }

                // Skip if consecutive count exceeds k
                if (next_count > k) continue;

                // Update minimum distance
                if (wt + w < dist[v][next_count]) {
                    dist[v][next_count] = wt + w;
                    pq.push({wt + w, v, next_count});
                }
            }
        }

        // Destination is unreachable
        return -1;
    }
};