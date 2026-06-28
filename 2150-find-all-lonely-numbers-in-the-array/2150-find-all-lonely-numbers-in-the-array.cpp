class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int n: nums)
        {
            mp[n]++;
        }

        vector<int> res;

        for(int n: nums)
        {
            if(mp[n]==1 && mp[n-1]==0 &&  mp[n+1]==0)
                res.push_back(n);
        }
        return res;
    }
};