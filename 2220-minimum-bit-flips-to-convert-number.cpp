class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorV= start ^ goal;
        return __builtin_popcount(xorV);
    }
};