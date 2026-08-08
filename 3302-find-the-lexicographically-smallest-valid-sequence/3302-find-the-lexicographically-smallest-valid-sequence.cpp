class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();

        vector<int> last(m, -1);

        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> ans(m);

        // We are allowed to change at most one character.
        bool chance = true;

        j = 0;

        // Try to build word2 from left to right.
        for (int i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {

                ans[j] = i;
                j++;
            }

            // don't match.
            // We can use our one allowed change here,
            // but only if the remaining characters of word2 can still be matched after this position.
            else if (chance && (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;

                chance = false;
            }

            // matched all characters.
            if (j == m)
                return ans;
        }

        return {};
    }
};