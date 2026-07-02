class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<times.size();i++)
        {
            int s = times[i][0] - 1;
            int d = times[i][1] - 1;
            int wt = times[i][2];

            adj[s].push_back({d,wt});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n,INT_MAX);

        int src = k - 1;

        pq.push({0,src});
        dist[src] = 0;

        while(!pq.empty())
        {
            pair<int,int> p = pq.top();
            pq.pop();

            int dis = p.first;
            int node = p.second;

            if(dis > dist[node])
                continue;

            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;

                if(dis + wt < dist[neigh])
                {
                    dist[neigh] = dis + wt;

                    pq.push({dist[neigh],neigh});
                }
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};