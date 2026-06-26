class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        vector<long long> prefSum(n);
        prefSum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefSum[i]=prefSum[i-1]+nums[i];
        }

        long long result=LLONG_MIN;

        for(int st=0;st<k;st++)
        {
            long long cur=0;
            int i=st;
            while(i<n && i+k-1<n)
            {
                int j=i+k-1;

                long long sum=prefSum[j]-((i>0)? prefSum[i-1] : 0);
                cur=max(sum,cur+sum);

                result=max(result,cur);

                i+=k;
            }
        }
        return result;
    }
};