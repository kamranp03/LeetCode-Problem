class Solution {
public:
    // cycle detection
    bool isCycle(int src,vector<vector<int>>& adj, vector<bool>& vis,vector<bool>& path)
    {
        vis[src]=true;
        path[src]=true;

        for(int i=0;i<adj[src].size();i++)
        {
            int neigh=adj[src][i];
            if(!vis[neigh])
            {
                if(isCycle(neigh,adj,vis,path))
                {
                    return true;
                }
            }else if(path[neigh])
            {
                return true;
            }
        }
        path[src]=false;
        return false;
    }

    //topo sort
    void topo(vector<vector<int>>& adj, int src, vector<bool>& vis, stack<int>& s)
    {
        vis[src]=true;

        for(int i=0;i<adj[src].size();i++)
        {
            int neigh=adj[src][i];

            if(!vis[neigh])
            {
                topo(adj,neigh,vis,s);
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> res;
        for(int i=0;i<edges.size();i++)
        {
            int src=edges[i][1];
            int dest=edges[i][0];

            adj[src].push_back(dest);
        }

        vector<bool> vis(adj.size(),false);
        vector<bool> path(adj.size(),false);

         for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(isCycle(i,adj,vis,path))
                {
                    return res;
                }
               
            }
        }

        stack<int> s;
        vis.assign(n,false);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                topo(adj,i,vis,s);
            }
        }

        while(s.size()>0)
        {
            res.push_back(s.top());
            s.pop();
        }

        return res;

    }
};