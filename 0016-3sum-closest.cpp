class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) {
        int n = nums.size();
        int maxDiff = INT_MAX;
        int resSum = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;
            int sum = -1 * nums[i];

            while(left < right)
            {
                int s = nums[left] + nums[right];

                int total = nums[i] + s;
                int diff = abs(total - tar);

                if(diff < maxDiff)
                {
                    maxDiff = diff;
                    resSum = total;
                }

                if(total == tar)
                {
                    return total;
                }
                else if(total > tar)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }

        return resSum;
    }
};