class Solution {
public:
    int memo[501][501]; // Constraints say lengths are <= 500

    int solve(string& word1, string& word2, int i, int idx) {
        // Base Cases
        if (i >= word1.length()) return word2.length() - idx; // Insert remaining chars of word2
        if (idx >= word2.length()) return word1.length() - i; // Delete remaining chars of word1
        
        // Return cached result if already computed
        if (memo[i][idx] != -1) return memo[i][idx];
        
        // If characters match, move both pointers without adding operations
        if (word1[i] == word2[idx]) {
            return memo[i][idx] = solve(word1, word2, i + 1, idx + 1);
        }
        
        // If characters don't match, try all 3 operations and take the minimum + 1
        int insertOp  = solve(word1, word2, i, idx + 1);       // Insert into word1
        int deleteOp  = solve(word1, word2, i + 1, idx);       // Delete from word1
        int replaceOp = solve(word1, word2, i + 1, idx + 1);   // Replace character
        
        return memo[i][idx] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        memset(memo, -1, sizeof(memo)); // Initialize memoization table with -1
        return solve(word1, word2, 0, 0);
    }
};