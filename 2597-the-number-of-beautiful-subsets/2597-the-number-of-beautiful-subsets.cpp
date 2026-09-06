class Solution {
public:
    int K;
    int res;
    void solve(int idx, unordered_map<int,int>& mp,vector<int>& nums)
    {
        if(idx>= nums.size())
        {
            res++;
            return;
        }

        //not take
        solve(idx+1,mp,nums);

        //take
        if(!mp[nums[idx]+K] && !mp[nums[idx]-K])
        {
            mp[nums[idx]]++;
            solve(idx+1,mp,nums);
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        K=k;
        res=0;
        unordered_map<int,int> mp;
        solve(0,mp,nums);
        return res-1;
    }
};