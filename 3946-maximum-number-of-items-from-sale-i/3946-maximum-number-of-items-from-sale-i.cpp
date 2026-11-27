class Solution {
public:
    // all code is like 0 1 knapsack only the extra copies parameter there
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& items, int budget, int n,
              vector<int>& copies, int minPrice) // start from last
    {
        if (n == 0) {
            return budget / minPrice;
        }
        if (dp[n][budget] != -1)
            return dp[n][budget];
        int take = 0, skip = 0;
        int price = items[n - 1][1];

        if (price <= budget) {
            // fist time we add extra copy in ans
            take = 1 + copies[n - 1] +
                   solve(items, budget - price, n - 1, copies, minPrice);
        }
        skip = solve(items, budget, n - 1, copies, minPrice);
        return dp[n][budget] = max(take, skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> copies(n, 0); // extra coppiies accroding to first rule
        int minPrice = INT_MAX;
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);
            int copy = 0;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;

                if (items[j][0] % items[i][0] == 0) // factor is there
                    copy++;
            }
            copies[i] = copy;
        }
        dp.assign(n + 1, vector<int>(budget + 1, -1));
        return solve(items, budget, n, copies, minPrice);
    }
};