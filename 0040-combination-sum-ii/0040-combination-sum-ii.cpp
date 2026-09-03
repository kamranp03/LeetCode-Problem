class Solution {
public:
    void backtrack(vector<int>& candidates, int target,
                   vector<int>& comb, int st,
                   vector<vector<int>>& res)
    {
        if(target == 0)
        {
            res.push_back(comb);
            return;
        }

        for(int i=st; i<candidates.size(); i++)
        {
            // Skip duplicate choices at same level
            if(i > st && candidates[i] == candidates[i-1])
                continue;

            // No need to check further
            if(candidates[i] > target)
                break;

            // Take
            comb.push_back(candidates[i]);

            // Move to next index because each element is used once
            backtrack(candidates, target-candidates[i],
                      comb, i+1, res);

            // Backtrack
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<int> comb;
        vector<vector<int>> res;

        backtrack(candidates, target, comb, 0, res);

        return res;
    }
};