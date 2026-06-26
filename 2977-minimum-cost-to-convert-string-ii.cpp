class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> P;
    ll BIG_Value= 1e10;

    unordered_map<string, vector<pair<string, ll>>> adj;

    unordered_map<string,unordered_map<string,ll>> dijkstraMemo;

    vector<ll> dpDemo;

    string srcstr;
    string tarstr;
    set<int> validlen;

    ll dijkstra(string start, string end)
    {
        if(dijkstraMemo[start].count(end)){
            return dijkstraMemo[start][end];
        }
        priority_queue<P, vector<P> , greater<P>> pq;

        unordered_map<string, ll> result;
        result[start]=0;
        pq.push({0, start});

        while(!pq.empty())
        {
            ll curcost = pq.top().first;
            string node = pq.top().second;

            pq.pop();

            if(node== end)
            {
                break;
            }

            for(auto &edge: adj[node])
            {
                string adjNode = edge.first;
                ll edgecost= edge.second;

                if(!result.count(adjNode) || curcost + edgecost < result[adjNode]){
                    result[adjNode] = curcost+ edgecost;
                    pq.push({curcost+edgecost , adjNode});
                }
            }
        }

        ll finalcost = result.count(end) ? result[end] : BIG_Value;

        return dijkstraMemo[start][end]=finalcost;
    }


    ll solve (int idx)
    {
        if(idx>= srcstr.length())
        {
            return 0;
        }
        if(dpDemo[idx] != -1)
        {
            return  dpDemo[idx];
        }

        ll mincost= BIG_Value;

        if(srcstr[idx] == tarstr[idx])
        {
            mincost=solve(idx+1);
        }

        for(auto &len: validlen)
        {
            if(idx +len  > srcstr.length()){
                break;
            }

            string srcsub= srcstr.substr(idx,len);
            string tarsub= tarstr.substr(idx, len);

            if(!adj.count(srcsub))
            {
                continue;
            }

            ll minPath =dijkstra(srcsub , tarsub);
            if( minPath == BIG_Value)
            {
                continue;

            }
            mincost= min( mincost, minPath + solve(idx +len));
        }
        return dpDemo[idx]=mincost;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        srcstr=source;
        tarstr=target;

        dpDemo.assign(10001, -1);

        for(int i=0;i<original.size(); i++)
        {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        for(auto &s: original)
        {
            validlen.insert(s.length());
        }

        ll res= solve(0);

        return res == BIG_Value ? -1: res;
    }
};