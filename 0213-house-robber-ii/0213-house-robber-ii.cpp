class Solution {
public:
    int helper(vector<int>& nums, int st, int end) {
       int p1= nums[st];
       int p2=max(nums[st],nums[st+1]);
       int res= p2;

       for(int i=st+2;i<=end;i++)
       {
        res=max(p2, nums[i]+p1);
        p1=p2;
        p2=res;
       }
       return res;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }
};