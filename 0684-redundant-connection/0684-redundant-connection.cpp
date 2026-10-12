// class Solution {
// public:
//     bool dfs(unordered_map<int, vector<int>>& mp, int u, int v, vector<bool>&
//     vis)
//     {
//         vis[u]=true;

//         if(u==v)
//         {
//             return true;
//         }

//         for(int& neigh: mp[u])
//         {
//             if(vis[neigh]) continue;

//             if(dfs(mp,neigh,v,vis))
//                 return true;
//         }
//         return false;
//     }
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n= edges.size();

//         unordered_map<int, vector<int>> mp;

//         for(int i=0;i<n;i++)
//         {
//             int u= edges[i][0];
//             int v= edges[i][1];
//             vector<bool> vis(n,false);
//             if(mp.find(u) != mp.end() && mp.find(v) != mp.end() &&
//             dfs(mp,u,v,vis))
//             {
//                 return {u,v};
//             }

//             mp[u].push_back(v);
//             mp[v].push_back(u);
//         }
//         return {};
//     }
// };
class DSU {
public:
    vector<int> par, rank;

    DSU(int n) {
        par.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            par[i] = i;
    }

    int find(int x) {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }

    void unionNode(int a, int b) {
        int A = find(a);
        int B = find(b);

        if (A == B)
            return;

        if (rank[A] == rank[B]) {
            par[B] = A;
            rank[A]++;
        } else if (rank[A] > rank[B]) {
            par[B] = A;
        } else {
            par[A] = B;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU ds(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (ds.find(u) == ds.find(v)) {
                return edge;
            }

            ds.unionNode(u, v);
        }
        return {};
    }
};