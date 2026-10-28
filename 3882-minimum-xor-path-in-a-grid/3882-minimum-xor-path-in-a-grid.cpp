class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> memo;

    int dfs(vector<vector<int>>& grid, int i, int j, int current_xor) {
        // Base case: out of bounds
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return 1e9; // Invalid path
        }
        
        // Include current cell in XOR path
        current_xor ^= grid[i][j];

        // Base case: reached bottom-right cell
        if (i == n - 1 && j == m - 1) {
            return current_xor;
        }

        // Return memoized result if already computed
        if (memo[i][j][current_xor] != -1) {
            return memo[i][j][current_xor];
        }

        // Try moving down or right
        int down = dfs(grid, i + 1, j, current_xor);
        int right = dfs(grid, i, j + 1, current_xor);

        // Memoize and return the minimum of both paths
        return memo[i][j][current_xor] = min(down, right);
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        // Initialize 3D vector with -1 on the heap (avoids stack overflow)
        memo.assign(n, vector<vector<int>>(m, vector<int>(1024, -1)));
        
        return dfs(grid, 0, 0, 0);
    }
};