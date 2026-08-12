class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int, int> mp;

        // Count frequency of each task
        for (int num : nums)
            mp[num]++;

        int round = 0;

        for (auto it : mp)
        {
            int count = it.second;

            // only 2 / 3 
            if (count == 1)
                return -1;

            // Prefer groups of 3 (greedy)
            if (count % 3 == 0)
            {
                round += count / 3;
            }
            else
            {
                // another grp of 2
                round += count / 3 + 1;
            }
        }

        return round;
    }
};