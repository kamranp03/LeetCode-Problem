class Solution {
public:
    vector<vector<int>> adj;
    int k, components;
    vector<int> &values;

    Solution() : values(*new vector<int>()) {} // Hack to allow reference

    int dfs(int node, int parent) {
        long long sum = values[node];

        for (int child : adj[node]) {
            if (child == parent) continue;
            sum += dfs(child, node);
        }

        if (sum % k == 0) {
            components++;
            return 0;
        }

        return sum % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& vals, int kk) {
        values = vals;
        k = kk;
        components = 0;

        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        return components;
    }
};
