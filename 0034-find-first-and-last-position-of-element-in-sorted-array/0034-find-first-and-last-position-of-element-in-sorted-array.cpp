class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int st = 0;
        int end = nums.size()-1;

        while(st <= end)
        {
            int mid = st + (end-st)/2;

            if(nums[mid] == target)
            {
                int i = mid;
                int j = mid;

                while(i >= 0 &&
                      nums[i] == target)
                {
                    i--;
                }

                while(j < nums.size() &&
                      nums[j] == target)
                {
                    j++;
                }

                return {i+1, j-1};
            }

            else if(nums[mid] < target)
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return {-1,-1};
    }
};