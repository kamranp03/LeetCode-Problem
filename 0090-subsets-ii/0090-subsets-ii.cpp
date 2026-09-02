class Solution {
public:
    vector<vector<int>> output;
    int n;

    void backtrack(int first, vector<int> curr, vector<int>& nums) {

        // Every current combination is a valid subset
        output.push_back(curr);

        for(int i = first; i < n; i++)
        {
            // Skip duplicate choices at the same level
            if(i > first && nums[i] == nums[i-1])
                continue;

            curr.push_back(nums[i]);

            // Move to next index so we don't reuse the same element
            backtrack(i + 1, curr, nums);

            // Remove last element and try another choice
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        n = nums.size();

        vector<int> curr;

        backtrack(0, curr, nums);

        return output;
    }
};