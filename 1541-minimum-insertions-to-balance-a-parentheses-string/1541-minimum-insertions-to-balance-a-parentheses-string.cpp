class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0; // Tracks required ')'
        int ans = 0; // Tracks insertions needed

        for (char c : s) {
            if (c == '(') {
                // If cnt is odd, we have an unclosed single ')' from before. 
                // We need to insert 1 ')' to make it a pair.
                if (cnt % 2 != 0) {
                    ans++;
                    cnt--;
                }
                cnt += 2; // Each '(' requires two ')'
            } else {
                cnt--; // Encountered a ')'
                // If cnt drops below 0, we have an extra ')' with no matching '('
                if (cnt < 0) {
                    ans++;     // Insert a missing '('
                    cnt += 2;  // That inserted '(' now needs two ')' (one is this current one, one is accounted for)
                }
            }
        }

        // Any leftover open parentheses need 2 ')' each
        return ans + cnt;
    }
};