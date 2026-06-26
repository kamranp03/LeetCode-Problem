class Solution {
public:

    void solve(vector<int>& candidates, int target, int idx,
               vector<int>& diary, vector<vector<int>>& res) {

        // Base Case
        if (idx == candidates.size()) {
            if (target == 0)
                res.push_back(diary);
            return;
        }

        // Take current element (can reuse it)
        if (candidates[idx] <= target) {
            diary.push_back(candidates[idx]);

            solve(candidates, target - candidates[idx],
                  idx, diary, res);

            diary.pop_back(); // Backtrack
        }

        // Not Take current element
        solve(candidates, target, idx + 1, diary, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        vector<int> diary;

        solve(candidates, target, 0, diary, res);

        return res;
    }
};