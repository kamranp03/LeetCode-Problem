// class Solution {
// public:
//     int minPath;
//     int n;
//     void dfs(vector<vector<int>>& grid,int i, int j,vector<vector<bool>>& vis, int& count)
//     {
//         if(i<0 || j<0 || i>=n || j>=n || vis[i][j] || grid[i][j]!= 0)
//             return;

//         if(i==n-1 && j==n-1)
//         {
//             minPath= min(minPath, count+1);
//             return;
//         }

//         vis[i][j]=true;
//         count++;

//         dfs(grid,i-1,j,vis,count);// top
//         dfs(grid,i+1,j,vis,count);// bottom
//         dfs(grid,i,j+1,vis,count);// right
//         dfs(grid,i,j-1,vis,count);// left

//         dfs(grid,i-1,j-1,vis,count);//top left dia
//         dfs(grid,i-1,j+1,vis,count);// top right dia
//         dfs(grid,i+1,j+1,vis,count);// bottom right dia
//         dfs(grid,i+1,j-1,vis,count);// bottom left dia

//         vis[i][j]=false;
//         count--;



//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         minPath=INT_MAX;
//         n= grid.size();
//         int count=0;
//         vector<vector<bool>> vis(n,vector<bool>(n,false));

//         dfs(grid,0,0,vis,count);

//         return minPath == INT_MAX? -1 : minPath;
//     }
// };

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }
        
        // Queue stores {row, col}
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        // Use grid itself to track distance/visited state to save space
        // grid[r][c] will store the distance from start
        grid[0][0] = 1; 
        
        // 8-directional movements
        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            int distance = grid[r][c];
            
            // If we reached the bottom-right cell
            if (r == n - 1 && c == n - 1) {
                return distance;
            }
            
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    q.push({nr, nc});
                    grid[nr][nc] = distance + 1; // Mark as visited and store path length
                }
            }
        }
        
        return -1;
    }
};