class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {

        // Out of bounds
        if(i >= n || j >= m)
            return false;

        // Update balance
        if(grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Too many closing brackets
        if(balance < 0)
            return false;

        // Not enough cells left to close brackets
        int remaining = (n - i) + (m - j) - 1;
        if(balance > remaining)
            return false;

        // At destination, balance must be zero
        if(i == n - 1 && j == m - 1)
            return balance == 0;

        // Already calculated this state
        if(dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // Go right or down
        bool right = solve(grid, i, j + 1, balance);
        bool down = solve(grid, i + 1, j, balance);

        return dp[i][j][balance] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();

        // Path length must be even
        if((n + m - 1) % 2 != 0)
            return false;

        // DP state = row, column, balance
        dp.assign(n, vector<vector<int>>(
            m, vector<int>(n + m, -1)
        ));

        return solve(grid, 0, 0, 0);
    }
};
// class Solution {
// public:
//     int open, close, n, m;
//     bool solve(vector<vector<char>>& grid, int i, int j) {
//         if (open > close || close > open) {
//             if (i == n - 1 && j == m - 1)
//                 return 0;
//         }
//         if(i>=n || j>=m)
//             return 0;

//         if (i == n - 1 && j == m - 1) {
//             return 1;
//         }

//         if (grid[i][j] == '(')
//             open++;
//         else
//             close++;

//         bool right = solve(grid, i, j + 1);
//         bool bottom = solve(grid, i + 1, j);

//         return right || bottom;
//     }
//     bool hasValidPath(vector<vector<char>>& grid) {
//         n = grid.size();
//         m = grid[0].size();
//         open = 0;
//         close = 0;

//         return solve(grid, 0, 0);
//     }
// };