class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];

            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> adj(n);

        for (int i = 0; i < connections.size(); i++) {
            int src = connections[i][0];
            int des = connections[i][1];

            adj[src].push_back(des);
            adj[des].push_back(src);
        }

        vector<bool> vis(n, false);

        int con = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                con++;
                dfs(i, adj, vis);
            }
        }

        return con - 1;
    }
};