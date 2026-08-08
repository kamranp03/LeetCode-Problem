class Solution {
public:
    bool possible(vector<int>& weights, int cap, int days) {
        int dayUsed = 1;
        int currentW = 0;

        for (int t : weights) {
            if (currentW + t <= cap) {
                currentW += t;
            } else {
                dayUsed++;
                currentW = t;
            }
        }

        return dayUsed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (possible(weights, mid, days)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};