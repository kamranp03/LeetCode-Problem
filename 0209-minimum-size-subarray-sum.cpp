class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int res = INT_MAX;
        int sum=0;
        int r=0;

        while(r<n)
        {
            sum+=nums[r];

            while(sum>=target)

            {
                int len= r-l+1;
                res= min(res,len);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return (res ==INT_MAX)? 0:res;
    }
};