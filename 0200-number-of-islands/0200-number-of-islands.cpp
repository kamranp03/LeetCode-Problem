class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i, int j, int n, int m,vector<vector<bool>>& vis)
    {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j] != '1')
        {
            return;
        }    
        vis[i][j]=true;

        dfs(grid,i-1,j,n,m,vis);
        dfs(grid,i,j+1,n,m,vis);
        dfs(grid,i+1,j,n,m,vis);
        dfs(grid,i,j-1,n,m,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == false){
                dfs(grid,i,j,n,m,vis);
                island++;
                }
            }
        }
   return island;
        
    }
};