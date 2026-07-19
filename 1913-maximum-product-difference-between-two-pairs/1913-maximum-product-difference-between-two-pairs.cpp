class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int mx1= nums[nums.size()-1];
        int mx2=nums[nums.size()-2];

        int mn1=nums[0];
        int mn2=nums[1];

        return (mx1*mx2)-(mn1*mn2);
    }
};