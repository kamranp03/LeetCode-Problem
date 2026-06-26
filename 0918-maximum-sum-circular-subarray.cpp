class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int total = 0;

        int maxEnding = a[0], maxSum = a[0];
        int minEnding = a[0], minSum = a[0];

        for(int i = 0; i < a.size(); i++) {
            total += a[i];

            if(i > 0) {
                maxEnding = max(a[i], maxEnding + a[i]);
                maxSum = max(maxSum, maxEnding);

                minEnding = min(a[i], minEnding + a[i]);
                minSum = min(minSum, minEnding);
            }
        }

        
        if(maxSum < 0) return maxSum;

        return max(maxSum, total - minSum);
    }
};