class Solution {
public:
    bool isCycle(int src,vector<bool>& vis,vector<bool>& path,vector<vector<int>>& adj)
    {
        vis[src]=true;
        path[src]=true;

        for( int neigh: adj[src])
        {
            if(!vis[neigh])
            {
                if(isCycle(neigh,vis,path,adj))
                    return true;
            }else if(path[neigh])
            {
                return true;
            }
        }
        path[src]=false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int src=edges[i][0];
            int dest=edges[i][1];

            adj[src].push_back(dest);
        }

        vector<bool> vis(n,false);
        vector<bool> path(n,false);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(isCycle(i,vis,path,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};