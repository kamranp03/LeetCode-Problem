class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minEle = *min_element(nums.begin(), nums.end());
        int count = 0;

        for (int n : nums) {
            count +=
                (n - minEle); // count moves , take difference which actually
                              // needed moves tomake that elemt to min ele
        }
        return count;
    }
};

// instead of incrementing elemnt , we focus on decrementing ele,
// n-1 elements increament by 1 = decrese element by 1 to make like smallest
// elemnt in array