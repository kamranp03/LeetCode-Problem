class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            res += (i + 1) * (26 - (s[i] - 'a'));
        }
        return res;
    }
};