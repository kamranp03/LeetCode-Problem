class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long BEFORE abs
        long long a = llabs((long long) dividend);
        long long b = llabs((long long) divisor);

        long long result = 0;

        // Bit manipulation division
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;

        // Clamp to 32-bit signed range
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int) result;
    }
};
