class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp )
    {
        if(i>=n || j>=m || grid[i][j]==1)
        {
            return 0;
        }
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!= -1)
        {
            return dp[i][j];
        }

        return dp[i][j]=solve(i+1,j,n,m,grid,dp) + solve(i,j+1,n,m,grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(0,0,n,m,grid,dp);
    }
};