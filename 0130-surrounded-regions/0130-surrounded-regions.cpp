class Solution {
public:
    bool isValid(int i,int j, int n, int m)
    {
        if(i<0 || j<0 || i>n || j>m )
            return false;
        return true;    
    }

    void dfs(vector<vector<char>>& board, int i,int j, int n , int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O')
            return;
        
        board[i][j]='#';

        dfs(board,i-1,j,n,m);//top
        dfs(board,i,j+1,n,m);//right
        dfs(board,i+1,j,n,m);//bottom
        dfs(board,i,j-1,n,m);//left
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        //top row
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                dfs(board,0,j,n,m);
            }
        }

        //bottom row
        for(int j=0;j<m;j++)
        {
            if(board[n-1][j]=='O')
            {
                dfs(board,n-1,j,n,m);
            }
        }

        //first coloumn
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(board,i,0,n,m);
            }
        }

        //last coloumn
        for(int i=0;i<n;i++)
        {
            if(board[i][m-1]=='O')
            {
                dfs(board,i,m-1,n,m);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='#')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }

    }
};