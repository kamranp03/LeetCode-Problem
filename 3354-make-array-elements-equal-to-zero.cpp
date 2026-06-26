class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Helper lambda to simulate the process
        auto simulate = [&](int start, int dir) {
            vector<int> a = nums;
            int curr = start;
            int d = dir;

            while (curr >= 0 && curr < n) {
                if (a[curr] == 0) {
                    curr += d;
                } else {
                    a[curr]--;
                    d = -d; // reverse direction
                    curr += d;
                }
            }

            for (int x : a)
                if (x != 0)
                    return false;
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (simulate(i, 1)) ans++;
                if (simulate(i, -1)) ans++;
            }
        }

        return ans;
    }
};
