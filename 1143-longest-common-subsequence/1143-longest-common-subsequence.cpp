class Solution {
public:
    int n, m;
    
int solve(const string& text1, const string& text2, int i, int idx, vector<vector<int>>& dp) {
    if (idx >= m || i >= n) return 0; // for out ofbound
    
    if (dp[i][idx] != -1) return dp[i][idx];
    
    // take choice (if both text char is same)
    if (text1[i] == text2[idx]) {
        return dp[i][idx] = 1 + solve(text1, text2, i + 1, idx + 1, dp);
    }
    
    // Try both choices when characters don't match and take the max
    int option1 = solve(text1, text2, i + 1, idx, dp);     // skip in text1
    int option2 = solve(text1, text2, i, idx + 1, dp);     // skip in text2
    
    // take max from both option
    return dp[i][idx] = max(option1, option2);
}
    
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};