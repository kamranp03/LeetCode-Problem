//  code 1 with Tc- o(n) sc- o(n);
// class Solution {
// public:
//     vector<int> findArray(vector<int>& pref) {
//         int n = pref.size();

//         vector<int> ans;

//         ans.push_back(pref[0]);

//         for (int i = 1; i < n; i++) {
//             ans.push_back(pref[i] ^ pref[i - 1]);
//         }
//         return ans;
//     }
// };

// code 2 Tc-o(n) Sc - o(1)
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        for (int i = n - 1; i > 0; i--) {
            pref[i] = pref[i] ^ pref[i - 1];
        }
        return pref;
    }
};