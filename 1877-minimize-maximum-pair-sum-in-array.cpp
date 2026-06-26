class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int maxS=0;
        int i=0;
        int j=nums.size()-1;

        while(i<j)
        {
            maxS= max(maxS , nums[i]+nums[j]);
            i++;
            j--;
        }
        
        return maxS;
   }
};