class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int ones=0;
        bool res=false;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count++;
            }else if(nums[i]==1)
            {
                ones++;
                if(count>=k)
                {
                    res=true;
                }else{
                    res=false;
                }
                count=0;
            }
        }
        if(ones<=1)
        {
            res=true;
        }
        return res;
    }
};