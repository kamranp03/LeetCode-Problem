class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefMax(n,INT_MIN);
        vector<int> suffMin(n,INT_MAX);
        prefMax[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int maxi= max(nums[i],prefMax[i-1]);
            prefMax[i]=maxi;
        }

        suffMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int mini= min(nums[i],suffMin[i+1]);
            suffMin[i]=mini;
        }

        for(int i=0;i<n;i++)
        {
            int ans= prefMax[i]-suffMin[i];

            if(ans<=k) return i;
        }
        return -1;
    }
};