class Solution {
public:
    bool isSafe(vector<string> &board, int n, int row,int col)
    {
        //horizontal
        for(int i=0;i<n;i++)
        {
            if(board[row][i]=='Q')
            return false;
        }

        //vertical
        for(int j=0;j<n;j++)
        {
            if(board[j][col]=='Q')
            return false;
        }

        //left dia
        for(int i=row,j=col;i>=0 && j>=0; i--,j--)
        {
            if(board[i][j]=='Q')
            return false;
        }

        //right dia
        for(int i=row,j=col;i>=0 && j<n; i--,j++)
        {
            if(board[i][j]=='Q')
            return false;
        }

        return true;
    }
    void nQ(vector<string> &board, int n, int row, vector<vector<string>> &res)
    {
        if(row==n)
        {
            res.push_back({board});
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(isSafe(board,n,row,i))
            {
                board[row][i]='Q';
                nQ(board,n,row+1,res);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nQ(board,n,0,ans);

        return ans;
    }
};