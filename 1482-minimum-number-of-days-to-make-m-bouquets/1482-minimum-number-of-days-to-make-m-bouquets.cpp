class Solution {
public:

    bool possible(vector<int>& bloomDay, int days, int m, int k)
    {
        int bouquets = 0;
        int flowers = 0;

        for (int day : bloomDay)
        {
            if (day <= days)
            {
                
                flowers++;

                // k adjecent gott
                if (flowers == k)
                {
                    bouquets++;
                    flowers = 0; // These flowers are used
                }
            }
            else
            {
                // want ajecent so 
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k)
    {
        long long required = 1LL * m * k;

        // Not enough flowers in total
        if (required > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k))
            {
                // mid days are enough
                // Try left
                ans = mid;
                high = mid - 1;
            }
            else
            {
                // try right 
                low = mid + 1;
            }
        }

        return ans;
    }
};