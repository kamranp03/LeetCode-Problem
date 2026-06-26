class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        vector<vector<int>> result;

        // Find minimum difference
        for (int i = 0; i < arr.size() - 1; i++) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        // Collect all pairs with minimum difference
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] == minDiff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        return result;
    }
};
