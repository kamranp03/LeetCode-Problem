class Solution {
public:
    int n, m;
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, bool& ans) {
        // if out of bount touch corner, so not sorrounded by water
        if (i < 0 || i >= n || j < 0 || j >= m) {
            ans = false;
            return;
        }
        
        // If already water or visited  return
        if (grid[i][j] == 1 || vis[i][j]) {
            return;
        }
        
        vis[i][j] = true;
        
        // Explore all 4 directions
        dfs(grid, i + 1, j, vis, ans);
        dfs(grid, i - 1, j, vis, ans);
        dfs(grid, i, j + 1, vis, ans);
        dfs(grid, i, j - 1, vis, ans);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if unvisited land 
                if (!vis[i][j] && grid[i][j] == 0) {
                    bool ans = true; // Reset ans for every new island
                    dfs(grid, i, j, vis, ans);
                    if (ans) { // after call ans if true meand surrounded by water no corner touch
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};