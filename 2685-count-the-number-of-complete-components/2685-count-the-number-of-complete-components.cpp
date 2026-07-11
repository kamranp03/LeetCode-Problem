class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis, int& nodes,
             int& edgesCnt) {
        vis[node] = true;

        nodes++;

        edgesCnt += adj[node].size();

        for (int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];

            if (!vis[neigh]) {
                dfs(adj, neigh, vis, nodes, edgesCnt);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int edgesCnt = 0;

                dfs(adj, i, vis, nodes, edgesCnt);

                int actualEdges = edgesCnt / 2;

                int requiredEdges = nodes * (nodes - 1) / 2;

                if (actualEdges == requiredEdges) {
                    ans++;
                }
            }
        }

        return ans;
    }
};