class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int min_from_start= nums[n-1]-nums[2];
        int max_from_end= nums[n-3]- nums[0];
        int start_end= nums[n-2]- nums[1];

        return min({min_from_start,max_from_end,start_end});

    }
};