class Solution {
public:

    bool avail(vector<int>& row, int start)
    {
        for (int i = start; i < start + 4; i++)
        {
            if (row[i] == 1)
                return false;
        }

        return true;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
    {
        unordered_map<int, vector<int>> seats;

        // Store only rows that have reserved seats
        for (auto &x : reservedSeats)
        {
            int r = x[0];
            int c = x[1];

            if (seats.find(r) == seats.end())
                seats[r] = vector<int>(11, 0);

            seats[r][c] = 1;
        }

        // Initially every row can fit 2 families
        long long ans = 2LL * n;

        // Only check rows that have reservations
        for (auto &x : seats)
        {
            int row = x.first;

            bool left = avail(x.second, 2);
            bool middle = avail(x.second, 4);
            bool right = avail(x.second, 6);

            // This row was initially counted as 2
            if (left && right)
            {
                // Still 2 families
            }
            else if (left || middle || right)
            {
                // Actually only 1 family
                ans -= 1;
            }
            else
            {
                // No group of 4 available
                ans -= 2;
            }
        }

        return ans;
    }
};