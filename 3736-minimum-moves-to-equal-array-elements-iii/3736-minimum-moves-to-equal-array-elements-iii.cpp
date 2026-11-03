class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves=0;
        int mx= *max_element(nums.begin(), nums.end());

        for(int num: nums)
        {
            moves+= (mx-num);
        }

        return moves;
    }
};