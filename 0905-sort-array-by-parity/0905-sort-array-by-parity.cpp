class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int i=0;
        int j=nums.size()-1;

        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]%2==0)
            {
                res[i]=nums[k];
                i++;
            }else
            {
                res[j]=nums[k];
                j--;
            }
        }
        return res;
    }
};