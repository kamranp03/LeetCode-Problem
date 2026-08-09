class Solution {
public:
    int getSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = getSum(x);

        if (x % sum == 0)
            return sum;

        return -1;
    }
};