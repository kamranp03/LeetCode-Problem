class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1},{ 0, -1}};
    int backtrack(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }

        int currGold = grid[i][j];
        grid[i][j]=0;

        int maxG=0;
        for (vector<int>& dir : directions) {
            int x = i + dir[0];
            int y= j+ dir[1];

            maxG= max(maxG,backtrack(grid,x,y));
        }

        grid[i][j]=currGold;
        return currGold+ maxG;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int maxGold = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxGold = max(maxGold, backtrack(grid, i, j));
            }
        }
        return maxGold;
    }
};