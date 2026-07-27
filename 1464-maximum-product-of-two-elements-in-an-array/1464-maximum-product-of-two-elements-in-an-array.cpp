class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mx1=nums[n-1];
        int mx2=nums[n-2];

        return (mx1-1)*(mx2-1);
    }
};