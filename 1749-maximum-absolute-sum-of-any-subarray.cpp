class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int maxEnding = a[0], minEnding = a[0];
        int maxSum = a[0], minSum = a[0];

        for(int i = 1; i < a.size(); i++) {
            maxEnding = max(a[i], maxEnding + a[i]);
            minEnding = min(a[i], minEnding + a[i]);

            maxSum = max(maxSum, maxEnding);
            minSum = min(minSum, minEnding);
        }

        return max(abs(maxSum), abs(minSum));
    }
};