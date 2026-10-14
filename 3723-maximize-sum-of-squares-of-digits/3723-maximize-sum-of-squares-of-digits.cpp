class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";

        while (num--) {
            if (sum >= 10 ) {
                res += '9';
                sum -= 9;
            } else if (sum < 10 && sum > 0) {
                res += to_string(sum % 10);
                sum -= sum % 10;
            } else {
                res += '0';
            }
        }
        return sum != 0 ? "" : res;
    }
};