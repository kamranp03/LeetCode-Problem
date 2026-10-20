class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i >= n || j >= m) return 1e9; // out of bound , return max 
        
        // get that last idx 
        if (i == n - 1 && j == m - 1) return grid[i][j];
        
        if (dp[i][j] != -1) return dp[i][j];
        
        // Move Down or Move Right
        int down = grid[i][j] + solve(i + 1, j, n, m, grid, dp);
        int right = grid[i][j] + solve(i, j + 1, n, m, grid, dp);
        
        // only minimum path for that grid
        return dp[i][j] = min(down, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, grid, dp);
    }
};