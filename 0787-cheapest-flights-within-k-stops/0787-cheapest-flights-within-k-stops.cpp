class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < flights.size(); i++) {
            int s = flights[i][0];
            int d = flights[i][1];
            int wt = flights[i][2];

            adj[s].push_back({d, wt});
        }

        queue<vector<int>> q;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        q.push({src, 0, 0}); // node,cost,stops

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int node = curr[0];
            int cost = curr[1];
            int stops = curr[2];

            if (stops > k)
                continue;

            for (int i = 0; i < adj[node].size(); i++) {
                int neigh = adj[node][i].first;
                int wt = adj[node][i].second;

                if (cost + wt < dist[neigh]) {
                    dist[neigh] = cost + wt;

                    q.push({neigh, dist[neigh], stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};