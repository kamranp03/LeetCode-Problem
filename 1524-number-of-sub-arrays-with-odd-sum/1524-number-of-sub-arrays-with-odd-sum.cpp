class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr) {
        long long oddCount = 0;
        long long evenCount = 1; // Base case: prefix sum 0 is even
        long long currentPrefixSum = 0;
        long long totalOddSubarrays = 0;
        long long MOD = 1e9 + 7;

        for (int num : arr) {
            currentPrefixSum += num;

            if (currentPrefixSum % 2 != 0) {
                // If current prefix sum is odd, add the count of previous even prefix sums
                totalOddSubarrays = (totalOddSubarrays + evenCount) % MOD;
                oddCount++;
            } else {
                // If current prefix sum is even, add the count of previous odd prefix sums
                totalOddSubarrays = (totalOddSubarrays + oddCount) % MOD;
                evenCount++;
            }
        }

        return totalOddSubarrays;
    }
};