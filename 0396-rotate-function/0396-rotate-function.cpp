class Solution {
public:
    int n;

    long long F(vector<int>& num) {
        long long sum = 0;
        long long ans = 0;

        // Calculate total sum and initial rotation F(0)
        for (int i = 0; i < n; i++) {
            sum += num[i];
            ans += 1LL * num[i] * i;
        }

        long long mx = ans;

        // Calculate all next rotations using the previous result
        for (int i = n - 1; i > 0; i--) {

            // Formula: New F = Previous F + Total Sum - n * Last Element
            ans = ans + sum - 1LL * n * num[i];

            // Store the maximum rotation function
            mx = max(mx, ans);
        }

        return mx;
    }

    int maxRotateFunction(vector<int>& nums) {
        n = nums.size();
        return F(nums);
    }
};

// class Solution {
// public:
//     int n;
//     int F(int i, vector<int>& num) {
//         int sum = 0;
//         int count = 0;
//         while (count < n) {
//             if (i == n) {
//                 i = 0;
//             }
//             sum += num[i++] * count;
//             count++;
//         }
//         return sum;
//     }
//     int maxRotateFunction(vector<int>& nums) {
//         n = nums.size();

//         int sum = INT_MIN;
//         for (int i = 0; i < n; i++) {
//             sum = max(sum, F(i, nums));
//         }
//         return sum;
//     }
// };