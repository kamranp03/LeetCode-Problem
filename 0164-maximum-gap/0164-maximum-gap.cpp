class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxG=0;
        if(nums.size()==1)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            int gap= nums[i+1]-nums[i];
            maxG= max(maxG,gap);
        }
        return maxG;
    }
};