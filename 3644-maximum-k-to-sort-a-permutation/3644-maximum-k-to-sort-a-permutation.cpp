class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1; // start k from -1 bcz, binary for -1 is same as 1

        for (int i=0; i<n; i++)
        {
            if (nums[i] != i)   // checking if curr ele is not sorted
            {
                k &= nums[i];   // AND with curr ele
            }
        }

        return k == -1 ? 0 : k; 
    }
};