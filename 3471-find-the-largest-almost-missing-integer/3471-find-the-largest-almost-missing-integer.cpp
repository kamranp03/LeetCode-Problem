class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int i=0,j=k-1;

        while(j<nums.size())
        {
            unordered_set<int> seen;

            int temp=i;

            while(temp<=j)
            {
                seen.insert(nums[temp]);
                temp++;
            }

            for(int x: seen)
                mp[x]++;

            i++;
            j++;    
        }

        int ans=-1;

        for(auto& [x,f]:mp)
        {
            if(f==1)
                ans= max(ans,x);
        }
        return ans;
    }
};