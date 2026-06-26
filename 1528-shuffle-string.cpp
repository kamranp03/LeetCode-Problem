class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
      int n = indices.size();
        vector<char> res(n);
        for (int i = 0; i < n; ++i) {
            res[indices[i]] = s[i];
        }
        return string(res.begin(), res.end());
    }
};