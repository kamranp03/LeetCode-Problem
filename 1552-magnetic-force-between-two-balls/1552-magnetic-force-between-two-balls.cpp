class Solution {
public:
    bool possible(vector<int>& position, int mid, int m) {
        // Place the first ball at the first position
        int count = 1;
        int last = position[0];

        // Try to place remaining balls
        for (int i = 1; i < position.size(); i++) {

            // If current position is enough from the previous ball
            if (position[i] - last >= mid) {
                // Place a ball here
                count++;

                // Update last placed ball
                last = position[i];

                // all m  ball placed
                if (count >= m)
                    return true;
            }
        }

        // not able to placed all balls
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(), position.end());

        // Minimum possible distance
        int low = 1;

        // Maximum possible distance
        int high = position.back() - position.front();

        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check for mid distanch
            if (possible(position, mid, m)) {// yes try for bigger
                
                ans = mid;
                low = mid + 1;
            } else {// No try for smaller
                
                high = mid - 1;
            }
        }

        return ans;
    }
};