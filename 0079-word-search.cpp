class Solution {
public:

    bool dfs(vector<vector<char>>& board,
             string& word,
             int row,
             int col,
             int idx)
    {
        // all characters matched
        if(idx == word.size())
            return true;

        // invalid cell
        if(row < 0 || col < 0 ||
           row >= board.size() ||
           col >= board[0].size() ||
           board[row][col] != word[idx])
        {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';   // mark visited

        bool found =
            dfs(board, word, row+1, col, idx+1) ||
            dfs(board, word, row-1, col, idx+1) ||
            dfs(board, word, row, col+1, idx+1) ||
            dfs(board, word, row, col-1, idx+1);

        board[row][col] = temp;  // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};