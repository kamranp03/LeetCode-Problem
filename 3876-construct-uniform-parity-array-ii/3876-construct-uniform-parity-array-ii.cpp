class Solution {
public:
    /*logic is that check there are 3 cases in that
       1. all array even -> in that ans is true
       2. all array in odd-> same ans is true
       3. array contain both->
         a.mn val is odd then we can change all array to  odd
         b. mn val of even then impossible to chnage array (only possible when all aaray even)
    */
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];

        bool hasOdd = false;
        for (int v : nums1) {
            if (v < mn) {
                mn = v;
            }
            if (v & 1)
                hasOdd = true;
        }
        if (mn & 1)
            return true;

        return !hasOdd;
    }
};