class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Define the four boundaries
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        
        while (top <= bottom && left <= right) {
            // 1. Traverse from Left to Right along the top boundary
            for (int j = left; j <= right; j++) {
                res.push_back(matrix[top][j]);
            }
            top++; // Shrink top boundary
            
            // 2. Traverse from Top to Bottom along the right boundary
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--; // Shrink right boundary
            
            // 3. Traverse from Right to Left along the bottom boundary
            // We need to check if top <= bottom because the boundaries might have crossed
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    res.push_back(matrix[bottom][j]);
                }
                bottom--; // Shrink bottom boundary
            }
            
            // 4. Traverse from Bottom to Top along the left boundary
            // We need to check if left <= right because the boundaries might have crossed
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++; // Shrink left boundary
            }
        }
        
        return res;
    }
};