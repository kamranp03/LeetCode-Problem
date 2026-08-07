class Solution {
public:
    string smallestNumber(string num, long long t) {

        long long temp = t;

        // Remove all prime factors 2 to 9 from t.
        // If something > 1 remains, it contains a prime > 7,
        // so it is impossible because digits (1-9) cannot produce it.
        for (int i = 2; i <= 9; i++) {
            while (temp % i == 0)
                temp /= i;
        }

        if (temp > 1)
            return "-1";

        int n = num.length();

        // rem[i] = remaining value of t after considering
        // first i digits of num.
        vector<long long> rem(n + 1);
        rem[0] = t;

        // Position of first zero.
        // If no zero exists, pos = last index.
        int pos = n - 1;

        for (int i = 0; i < n; i++) {

            // We cannot keep zero.
            // We will modify from here.
            if (num[i] == '0') {
                pos = i;
                break;
            }

            // Remove common factors contributed by current digit.
            rem[i + 1] = rem[i] / gcd(rem[i], (long long)(num[i] - '0'));
        }

        // Current number already satisfies condition.
        if (rem[n] == 1)
            return num;

        // Try changing digits from RIGHT to LEFT.
        for (int i = pos; i >= 0; i--) {

            // Increase current digit.
            while (++num[i] <= '9') {

                // Remaining value after taking current digit.
                long long tNow =
                    rem[i] / gcd(rem[i], (long long)(num[i] - '0'));

                int k = 9;

                // Fill suffix with largest possible digits first.
                for (int j = n - 1; j > i; j--) {

                    while (k > 1 && tNow % k != 0)
                        k--;

                    if (k == 1) {
                        num[j] = '1';
                    } else {
                        tNow /= k;
                        num[j] = char('0' + k);
                    }
                }

                // If every factor of t is covered,
                // answer is found.
                if (tNow == 1)
                    return num;
            }
        }

        // Need one extra digit.

        string ans;

        // Build answer using largest factors first.
        for (int i = 9; i > 1; i--) {

            while (t % i == 0) {
                ans += char('0' + i);
                t /= i;
            }
        }

        // Fill remaining places with '1'.
        ans += string(max(n + 1 - (int)ans.length(), 0), '1');

        // Reverse to obtain lexicographically smallest answer.
        ranges::reverse(ans);

        return ans;
    }
};