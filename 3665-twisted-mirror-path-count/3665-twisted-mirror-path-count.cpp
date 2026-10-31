class Solution {
public:
    int n, m;
    long long int mod = 1e9 + 7;    //bcz we want the result in this modulo (according to problem)
    vector<vector<vector<long long int>>> dp;   //using 3d DP (row, col, direction), bcz direction is essential bcz we need to switch it
    long long int dfs (vector<vector<int>>& grid, int i, int j, int dir)
    {
        //if out of bounds
        if (i >= n || j >= m)
        {
            return 0;
        }

        //if reached to destination
        if (i == n-1 && j == m-1)
        {
            return 1;
        }

        //if result already in DP, retrieve it
        if (dp[i][j][dir] != -1)
        {
            return dp[i][j][dir];
        }

        //if mirror comes
        if (grid[i][j] == 1)
        {
            //reflection happens, i.e. (dir == 0) is for right, therefore change direction to down (i.e. dir == 1)
            if (dir == 0)
            {
                dp[i][j][dir]= dfs(grid, i+1, j, 1);
            }
            //vice versa here
            else
            {
                dp[i][j][dir]= dfs(grid, i, j+1, 0);
            }
        }
        else    //normal cell no mirror
        {
            dp[i][j][dir] = (dfs(grid, i+1, j, 1) + dfs(grid, i, j+1, 0)) % mod;    //so check both the directions and when result will come from both mod it (why here ?? bcz here the main calculation is done)
        }
        return dp[i][j][dir];   //we are storing calculations in DP up there, therefore returning DP cell
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<vector<long long int>>(m, {-1, -1}));   //initially all cells as -1

        return dfs (grid, 0, 0, 0);
        
    }
};