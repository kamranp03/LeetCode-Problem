class Solution {
public:
    int addDigits(int n) {
        if(n<10)
            return n;

        return 1 + (n - 1) % 9;
    }
};