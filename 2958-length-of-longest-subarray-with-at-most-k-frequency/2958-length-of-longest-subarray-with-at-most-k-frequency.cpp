class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int maxLen=0;
        int len=0;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;

          while(freq[nums[i]]> k)
          {
            freq[nums[len]]--;
            len++;
          }
          maxLen= max( maxLen, i-len+1);
        }

        return maxLen;
    }
};