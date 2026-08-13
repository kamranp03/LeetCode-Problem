class Solution {
public:
    int partitionString(string s) {
        vector<int> last_seen(26, -1);

        int cnt = 0;
        int scs = 0; // start_current_string

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (last_seen[ch - 'a'] >= scs) {
                cnt++;
                scs = i;
            }
            last_seen[ch - 'a'] = i;
        }
        return cnt + 1;
    }
};