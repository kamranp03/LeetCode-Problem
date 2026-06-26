class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                count++;
            }
        }

        if(count>0)
        {
            return n-count;
        }

        int step=INT_MAX;

        for(int i=0;i<n;i++)
        {
            int GCD=nums[i];
            for(int j=i+1;j<n;j++)
            {
                GCD=gcd(GCD,nums[j]);

                if(GCD==1)
                {
                    step=min(step,j-i);
                    break;
                }
            }

        }
        if(step==INT_MAX)
        {
            return -1;
        }
        return step+(n-1);
    }
};