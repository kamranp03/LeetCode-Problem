class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int n = grid.size();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                mp[grid[i][j]]++;
            }
        }

        int mis = -1;
        int rep = -1;

        for (int i = 1; i <= n * n; i++) {
            if (mp.find(i) == mp.end()) {
                mis = i;
            }
            if (mp[i] > 1) {
                rep = i;
            }
        }

        return {rep, mis};
    }
};