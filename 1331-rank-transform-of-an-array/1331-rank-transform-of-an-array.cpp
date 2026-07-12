class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr;

        sort(temp.begin(), temp.end());

        unordered_map<int, int> mp;

        int rank = 1;

        for (int i = 0; i < temp.size(); i++) {
            if (mp.count(temp[i]) == 0) {
                mp[temp[i]] = rank;
                rank++;
            }
        }

        vector<int> res(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            res[i] = mp[arr[i]];
        }

        return res;
    }
};