class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        // check for all 32 bit
        for (int k = 0; k <= 31; k++) {
            // bit mast (use for checking bit and making bits)
            int temp = (1 << k);
            int one = 0, zero = 0;

            //check kth bit of all numbers
            for (int &n : nums) {
                //chcking kth bit is res is zero means kth bit is zero else 1
                if ((n & temp) == 0)
                    zero++;
                else
                    one++;
            }
            // check if there is extra one means kth bit is one set that bit in res
            if (one % 3 == 1)
                res = (res | temp);
        }
        return res;
    }
};