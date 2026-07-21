class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        // count existing 1s
        int cnt1 = count(s.begin(), s.end(), '1');

        int n = s.size();

        int prevZero = INT_MIN; // previous 0 block length
        int curZero = 0;        // current 0 block length
        int bestGain = 0;       // max extra 1s we can get

        int i = 0;

        while (i < n) {
            int start = i;

            // find one complete block
            while (i < n && s[i] == s[start]) {
                i++;
            }

            // block length
            int len = i - start;

            // only process 0-blocks
            if (s[start] == '0') {
                curZero = len;

                // gain = left 0 block + right 0 block
                bestGain = max(bestGain, prevZero + curZero);

                prevZero = curZero;
            }
        }

        // original 1s + best gain
        return cnt1 + bestGain;
    }
};