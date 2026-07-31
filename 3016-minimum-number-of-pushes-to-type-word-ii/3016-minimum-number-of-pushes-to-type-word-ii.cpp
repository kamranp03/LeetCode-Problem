class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        for (char ch : word) {
            mp[ch]++;
        }

        vector<pair<char, int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        int cnt = 1;
        int ans = 0;

        for (auto &ch : freq) {
            if (cnt <= 8) {
                ans += ch.second;
            }
            else if (cnt <= 16) {
                ans += ch.second * 2;
            }
            else if (cnt <= 24) {
                ans += ch.second * 3;
            }
            else {
                ans += ch.second * 4;
            }
            cnt++;
        }

        return ans;
    }
};