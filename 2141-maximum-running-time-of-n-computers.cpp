class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(long long b : batteries) sum += b;

        long long left = 0, right = sum / n, ans = 0;

        while(left <= right) {
            long long mid = (left + right) / 2;

            long long total = 0;
            for(long long b : batteries)
                total += min(b, mid);

            if(total >= mid * n) { 
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
