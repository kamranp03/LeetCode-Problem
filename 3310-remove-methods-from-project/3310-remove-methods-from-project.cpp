class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        // Build Graph
        vector<vector<int>> adj(n);

        for (int i = 0; i < invocations.size(); i++) {
            int src = invocations[i][0];
            int des = invocations[i][1];

            adj[src].push_back(des);
        }

        // Find all suspicious methods
        vector<bool> sus(n, false);

        queue<int> q;
        q.push(k);
        sus[k] = true;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {

                if (!sus[neigh]) {
                    sus[neigh] = true;
                    q.push(neigh);
                }
            }
        }

        bool possible = true;

        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];

            if (!sus[u] && sus[v]) {
                possible = false;
                break;
            }
        }

        vector<int> ans;

        if (!possible) {
            // not possible to remove

            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        } else {
            // possible

            for (int i = 0; i < n; i++) {
                if (!sus[i]) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};