class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> t(n+1,vector<int>(3,INT_MIN));
        t[n][0]=0;
        t[n][1]=INT_MIN;
        t[n][2]=INT_MIN;

        for(int i=n-1;i>=0;i--)
        {
            for(int rem=0;rem<=2;rem++)
            {
                int newRem=(rem+nums[i])%3;
                int take= t[i+1][newRem]==INT_MIN? INT_MIN:(t[i+1][newRem]+nums[i]);

                int skip=t[i+1][rem];

                t[i][rem]=max(take,skip);
            }
        }
        return t[0][0];

    }
};