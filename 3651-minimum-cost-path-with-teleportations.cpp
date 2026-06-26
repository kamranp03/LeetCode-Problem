class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;

        // dp[i][j] = minimum cost to reach bottom-right from (i,j)
        vector<vector<int>> dp(m, vector<int>(n, INF));

        // Collect all cells
        vector<pair<int,int>> cells;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({i, j});
            }
        }

        // Sort cells by grid value
        sort(cells.begin(), cells.end(),
            [&](const pair<int,int>& a, const pair<int,int>& b) {
                return grid[a.first][a.second] < grid[b.first][b.second];
            });

        // Initial DP without teleport (normal path)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = 0;
                } else {
                    if (i + 1 < m)
                        dp[i][j] = min(dp[i][j], grid[i + 1][j] + dp[i + 1][j]);
                    if (j + 1 < n)
                        dp[i][j] = min(dp[i][j], grid[i][j + 1] + dp[i][j + 1]);
                }
            }
        }

        // Apply teleport k times
        for (int t = 0; t < k; t++) {
            int best = INF;
            int start = 0;

            for (int i = 0; i < cells.size(); i++) {
                int r = cells[i].first;
                int c = cells[i].second;
                best = min(best, dp[r][c]);

                // When value changes, apply teleport benefit
                if (i + 1 == cells.size() ||
                    grid[cells[i + 1].first][cells[i + 1].second] != grid[r][c]) {

                    for (int j = start; j <= i; j++) {
                        int x = cells[j].first;
                        int y = cells[j].second;
                        dp[x][y] = min(dp[x][y], best);
                    }
                    start = i + 1;
                }
            }

            // Recalculate normal moves again
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) continue;
                    if (i + 1 < m)
                        dp[i][j] = min(dp[i][j], grid[i + 1][j] + dp[i + 1][j]);
                    if (j + 1 < n)
                        dp[i][j] = min(dp[i][j], grid[i][j + 1] + dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
