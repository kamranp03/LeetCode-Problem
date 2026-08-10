class Solution {
public:
    vector<int> dp;

    bool solve(int n)
    {
        // no stone left lose
        if (n == 0)
            return false;

        if (dp[n] != -1)
            return dp[n];

        // try all possible sqr
        for (int i = 1; i * i <= n; i++)
        {
            int square = i * i;

            // If opponent loses, current player wins
            if (!solve(n - square))
            {
                return dp[n] = true;
            }
        }

        // No wining mov
        return dp[n] = false;
    }

    bool winnerSquareGame(int n)
    {
        dp.assign(n + 1, -1);

        return solve(n);
    }
};