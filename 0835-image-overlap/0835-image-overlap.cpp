class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxC = 0;
        for (int x = -(n - 1); x < n; x++) {
            for (int y = -(n - 1); y < n; y++) {
                int cnt = 0;
                for (int i = 0; i < n && i + x < n; i++) {
                    for (int j = 0; j < n && j + y < n; j++) {
                        int nx = i + x;
                        int ny = j + y;

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (img1[nx][ny] == 1 && img2[i][j] == 1)
                                cnt++;
                        }
                    }
                }
                maxC = max(maxC, cnt);
            }
        }
        return maxC;
    }
};