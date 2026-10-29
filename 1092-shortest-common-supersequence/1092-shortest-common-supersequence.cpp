class Solution {
public:
    int n,m;
    int solve(string& str1, string& str2, int i, int j,
              vector<vector<int>>& dp) {
        
        // If str1 is completed, take remaining str2
        if (i == n) return m - j;

        // If str2 is completed, take remaining str1
        if (j == m) return n - i;

        // Return stored answer
        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match, take it once
        if (str1[i] == str2[j]) {
            return dp[i][j] =
                1 + solve(str1, str2, i + 1, j + 1, dp);
        }

        // Try taking a character from either string
        int take1 = solve(str1, str2, i + 1, j, dp);
        int take2 = solve(str1, str2, i, j + 1, dp);

        return dp[i][j] = 1 + min(take1, take2);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        n = str1.length(), m = str2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        solve(str1, str2, 0, 0, dp);

        // Reconstruct the string using DP lengths
        string ans = "";
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            }
            else { // check from dp , which call get minimum value add in str
                int take1 = solve(str1, str2, i + 1, j, dp);
                int take2 = solve(str1, str2, i, j + 1, dp);

                if (take1 < take2) { // str1 call get minimum
                    ans += str1[i++];
                } else { // str2 call get minimum
                    ans += str2[j++];
                }
            }
        }

        // Add remaining characters
        ans += str1.substr(i);
        ans += str2.substr(j);

        return ans;
    }
};

// 1. Start recursion from index 0 of both strings.
// 2. If characters match, take one character; otherwise, try both choices and store the minimum length in DP.
// 3. After recursion, reconstruct the string by comparing DP values and choosing the better character.
// 4. Append any remaining characters from either string to get the final SCS.