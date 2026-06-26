class Solution {
public:
    void perm(vector<int>& nums, int n, vector<int>& diary, vector<vector<int>>& res, vector<bool>& used)
    {
        if(diary.size()==n)
        {
            res.push_back(diary);
            return;
        }

        for(int i=0;i<n;i++)
        {
            //check used
            if(used[i]) continue;

            //if noe used take it
            diary.push_back(nums[i]);
            used[i]=true;

            //explore 
            perm(nums,n,diary,res,used);

            //backtrack
            diary.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> diary;
        vector<vector<int>> res;

        vector<bool> used(n,false);

        perm(nums,n,diary,res,used);
        return res;
    }
};