class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char, int> freq;
    for(char c : s) {
        freq[c]++;
    }

    vector<pair<char, int>> v(freq.begin(), freq.end());

    // sort by frequency (descending)
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    string result = "";

    for(auto &p : v) {
        result += string(p.second, p.first); // repeat char
    }
    return result;
    }
};