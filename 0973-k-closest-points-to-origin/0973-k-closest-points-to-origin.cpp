class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;

        for(vector<int>& it: points)
        {
            // calculate 
            double eeeu = hypot( it[0] - 0, it[1] -0);
            pq.push({eeeu,{it[0],it[1]}});

            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> res;
        
        while(!pq.empty())
        {
            int x= pq.top().second.first;
            int y= pq.top().second.second;
            pq.pop();
            res.push_back({x,y});
        }

        return res;

    }
};