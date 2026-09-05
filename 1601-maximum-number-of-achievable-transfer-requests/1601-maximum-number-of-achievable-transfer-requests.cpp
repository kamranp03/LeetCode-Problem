class Solution {
public:
    int res = INT_MIN;
    int m;
    void solve(int idx, int cnt, int n, vector<int>& result,
               vector<vector<int>>& requests) {
        if (idx >= m) {
            bool allZ = true;
            for (int i : result) {
                if (i != 0) {
                    allZ = false;
                    break;
                }
            }
            if (allZ)
                res = max(res, cnt);

            return;
        }
        //process req
        int from = requests[idx][0];
        int to = requests[idx][1];

        result[from]--;
        result[to]++;

        solve(idx + 1, cnt + 1, n, result, requests);

        //backtrack
        result[from]++;
        result[to]--;
        solve(idx + 1, cnt, n, result, requests);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();

        vector<int> result(n, 0);

        solve(0, 0, n, result, requests);
        return res;
    }
};