class Solution {
public:
    int memo[50001];
    int n;
    int getNext(vector<vector<int>>& arr, int l, int end) { // find next job using binary search
        int r = n - 1;
        int res = n + 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid][0] >= end) // we can take task
            {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
    int solve(int i, vector<vector<int>>& arr) {
        if (i >= n)
            return 0;

        if(memo[i] != -1) return memo[i];

        // here 2 choice if take we next idx where we can take job that is next start time will be greater or equal to current jon end time , so we calculate that time from getNext funtion 

        int next = getNext(arr, i + 1, arr[i][1]);
        int take = arr[i][2] + solve(next, arr); // add cuurent profut and pass to next
        int skip = solve(i + 1, arr); // simply move next

        return memo[i]=max(take, skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        n = startTime.size();
        memset(memo,-1, sizeof(memo));
        vector<vector<int>> arr(n, vector<int>(3, 0)); // {s,e,p}

        // make array with together (start,end, profit)
        for (int i = 0; i < n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        // sort with base on start point
        auto cmp = [&](auto& vec1, auto& vec2) { return vec1[0] < vec2[0]; };

        sort(arr.begin(), arr.end(), cmp);

        return solve(0, arr);
    }
};