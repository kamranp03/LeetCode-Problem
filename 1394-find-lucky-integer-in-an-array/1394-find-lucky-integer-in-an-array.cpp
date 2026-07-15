class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int, int> mp;

        for (int num : arr) {
            mp[num]++;
        }

        int ans = -1;

        for (auto p : mp) {
            if (p.first == p.second) {
                ans = max(ans, p.first);
            }
        }

        return ans;
    }
};