class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (auto& it : adj[node]) {
            int neigh = it.first;
            int wt = it.second;

            ans = min(ans, wt);

            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n + 1, false);

        dfs(1, adj, vis);

        return ans;
    }
};