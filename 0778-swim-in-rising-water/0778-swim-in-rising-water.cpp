class Solution {
public:

    bool valid(int r,int c,int n,int m)
    {
        if(r < 0 || c < 0 || r >= n || c >= m)
            return false;

        return true;
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(
            n,
            vector<int>(m,INT_MAX)
        );

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0],{0,0}});

        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int time = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(time > dist[row][col])
                continue;

            if(row == n-1 && col == m-1)
                return time;

            for(int k=0;k<4;k++)
            {
                int r = row + x[k];
                int c = col + y[k];

                if(!valid(r,c,n,m))
                    continue;

                int newTime =
                    max(time, grid[r][c]);

                if(newTime < dist[r][c])
                {
                    dist[r][c] = newTime;

                    pq.push({newTime,{r,c}});
                }
            }
        }

        return -1;
    }
};