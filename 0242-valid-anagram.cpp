class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ss;
        unordered_map<char, int> tt;

        if (s.size() != t.size())
            return false;

        for (char ch : s) {
            ss[ch]++;
        }
        for (char ch : t) {
            tt[ch]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (ss[s[i]] != tt[s[i]])
                return false;
        }
        return true;
    }
};