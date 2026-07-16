class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> pre(nums.size());
        int mx=INT_MIN;
        long long cnt=0;

        for(int i=0;i<nums.size();i++)
        {
            mx= max(nums[i],mx);
            pre[i]=gcd(nums[i],mx);
        }
        sort(pre.begin(),pre.end());

        int i=0;
        int j= pre.size()-1;
        while(i<j)
        {
            cnt+= gcd(pre[i],pre[j]);
            i++;
            j--;
        }
        return cnt;

    }
};