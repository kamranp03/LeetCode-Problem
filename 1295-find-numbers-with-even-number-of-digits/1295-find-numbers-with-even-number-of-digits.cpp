class Solution {
public:
    int getDigit(int num)
    {
        int count=0;
        while(num>0)
        {
            count++;
            num/=10;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++)
        {
            int count=getDigit(nums[i]);
            if(count%2==0) total++;
            
        }
        return total;
    }
};