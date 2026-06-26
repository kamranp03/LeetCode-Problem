class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans=0;
         queue<pair<pair<int,int>,int>> q;

         //push all rotten oranges
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }

        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;

            ans=max(ans,t);
            q.pop();

            //top
            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1)
            {
                q.push({{i-1,j},t+1});
                vis[i-1][j]=true;
            }

            // right
            if(j+1<m && !vis[i][j+1] && grid[i][j+1]==1)
            {
                q.push({{i,j+1},t+1});
                vis[i][j+1]=true;
            }

            //bottom
            if(i+1<n && !vis[i+1][j] && grid[i+1][j]==1)
            {
                q.push({{i+1,j},t+1});
                vis[i+1][j]=true;
            }

            //left
            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1)
            {
                q.push({{i,j-1},t+1});
                vis[i][j-1]=true;
            }
        }

        //check for fresh
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                    return -1;
            }
        }

        return ans;
    }
};