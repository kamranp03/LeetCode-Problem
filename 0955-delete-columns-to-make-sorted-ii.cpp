class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();

        int deletion = 0;
        vector<bool> alrdy(rows - 1, false);

        for (int c = 0; c < cols; c++) {
            bool deleted = false;

            
            for (int r = 0; r < rows - 1; r++) {
                if (!alrdy[r] && strs[r][c] > strs[r + 1][c]) {
                    deletion++;
                    deleted = true;
                    break;
                }
            }

            if (deleted) continue;

           
            for (int i = 0; i < rows - 1; i++) {
                if (!alrdy[i] && strs[i][c] < strs[i + 1][c]) {
                    alrdy[i] = true;
                }
            }
        }
        return deletion;
    }
};
