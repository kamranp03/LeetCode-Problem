class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        unordered_set<int> st;

        int mn = INT_MAX;
        int mx = INT_MIN;

        for (int x : nums) {
            st.insert(x);
            mn = min(mn, x);
            mx = max(mx, x);
        }

        vector<int> res;

        for (int i = mn; i <= mx; i++) {
            if (st.find(i) == st.end()) {
                res.push_back(i);
            }
        }

        return res;
    }
};