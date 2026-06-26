class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // Sort both arrays
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // Find maximum consecutive bars in horizontal
        int maxH = 1, curr = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxH = max(maxH, curr);
        }

        // Find maximum consecutive bars in vertical
        int maxV = 1;
        curr = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxV = max(maxV, curr);
        }

        // Maximum square side
        int side = min(maxH + 1, maxV + 1);

        // Return area
        return side * side;
    }
};
