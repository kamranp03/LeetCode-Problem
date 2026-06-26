class Solution {
public:
    bool knightT(vector<vector<int>>& grid,int row, int col,int n, int exval)
    {
        if(row<0 || row>=n || col<0 || col>=n || grid[row][col] != exval)
            return false;

        if(exval == (n*n)-1)
            return true;

       

        // 8 possible moves of kight
        bool ans1=knightT(grid,row-2,col+1,n,exval+1);
        bool ans2=knightT(grid,row-1,col+2,n,exval+1);
        bool ans3=knightT(grid,row+1,col+2,n,exval+1);
        bool ans4=knightT(grid,row+2,col+1,n,exval+1);
        bool ans5=knightT(grid,row+2,col-1,n,exval+1);
        bool ans6=knightT(grid,row+1,col-2,n,exval+1);
        bool ans7=knightT(grid,row-1,col-2,n,exval+1);
        bool ans8=knightT(grid,row-2,col-1,n,exval+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return knightT(grid,0,0,grid.size(),0);
    }
};