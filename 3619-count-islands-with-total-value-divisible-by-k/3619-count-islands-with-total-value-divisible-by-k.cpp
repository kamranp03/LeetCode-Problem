class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& grid,int i,int j,long long& count, vector<vector<bool>>& vis)
    {
        // invalid
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j] || grid[i][j]==0)
        {
            return;
        }

        vis[i][j]=true;
        count+= grid[i][j];

        dfs(grid,i+1,j,count,vis);
        dfs(grid,i,j+1,count,vis);
        dfs(grid,i-1,j,count,vis);
        dfs(grid,i,j-1,count,vis);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n= grid.size();
        m= grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n, vector<bool>(m,false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                long long count=0;
                if(grid[i][j] != 0 && !vis[i][j])
                {
                dfs(grid,i,j,count,vis);
                if(count%k==0) ans++;
                }
            }
        }
        return ans;

    }
};