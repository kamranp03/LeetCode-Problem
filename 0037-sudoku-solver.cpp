class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col,char dig)
    {
        //horizontal
        for(int j=0;j<9;j++)
        {
            if(board[row][j]==dig)
                return false;
        }

        // vertical 
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==dig)
                return false;
        }

        // grid check

        int sr=(row/3)*3;
        int sc=(col/3)*3;

        for(int i=sr;i<=sr+2;i++)
        {
            for(int j=sc;j<=sc+2;j++)
            {
                if(board[i][j]==dig)
                    return false;
            }
        }
        return true;
    }
    bool sudo(vector<vector<char>>& board, int row, int col)
    {
        int newrow=row,newcol=col+1;
        if(newcol==9)
        {
            newrow=row+1;;
            newcol=0;

        }

        if(row==9)
        {
            return true;
        }

        //if already num
        if(board[row][col] != '.')
        {
           return sudo(board,newrow,newcol);
        }

        //if empty
        for(char dig='1';dig<='9';dig++)
        {
            if(issafe(board,row,col,dig))
            {
                board[row][col]=dig;
                if(sudo(board,newrow,newcol))
                {
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudo(board, 0,0);
    }
};