class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int time = 0;
        int pre = neededTime[0];

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                time += min(pre, neededTime[i]);
                pre = max(pre, neededTime[i]);  // ✅ keep max time in current group
            } else {
                pre = neededTime[i];
            }
        }
        return time;
    }
};
