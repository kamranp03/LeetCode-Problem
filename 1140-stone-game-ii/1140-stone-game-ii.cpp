class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int M, vector<int>& piles) {

        int n = piles.size();

        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = INT_MIN;
        int sum = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            sum += piles[i + X - 1];

            int newM = max(M, X);

            // Current player's score difference
            int curr = sum - solve(i + X, newM, piles);

            ans = max(ans, curr);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        dp.assign(n, vector<int>(n + 1, -1));

        int diff = solve(0, 1, piles);

        int total = 0;
        for (int x : piles)
            total += x;

        // If difference = Alice - Bob:
        // Alice = (total + difference) / 2
        return (total + diff) / 2;
    }
};