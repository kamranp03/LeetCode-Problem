class Solution {
public:
    bool valid(int r,int c, int n, int m)
    {
        if(r<0 || r>= n || c<0 || c>=m)
            return false;

        return true;    
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> res(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};

        res[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();

            int dis=p.first;
            int row=p.second.first;
            int col=p.second.second;

            if(dis>res[row][col])
                continue;

            for(int k=0;k<4;k++)
            {
                int r=row+x[k];
                int c=col+y[k];

                if(!valid(r,c,n,m))
                    continue;

                int absDiff= abs(heights[row][col]-heights[r][c]);
                int newWt=max(absDiff,dis);

                if(newWt <res[r][c])
                {
                    res[r][c]=newWt;
                    pq.push({newWt,{r,c}});
                }
            }
        }
        return res[n-1][m-1];
    }
};