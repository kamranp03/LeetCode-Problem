class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> m;

        for(int x : nums)
        {
            if(m.find(x) != m.end())
            {
                return x;
            }
            m.insert(x);
        }
        return -1;
    }
};