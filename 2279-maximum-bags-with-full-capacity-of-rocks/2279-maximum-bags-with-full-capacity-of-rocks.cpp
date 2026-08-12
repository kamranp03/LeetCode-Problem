class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int addr) {
        int n = c.size();
        vector<int> rem(n);

        for (int i = 0; i < n; i++) {
            int temp = c[i] - r[i];
            rem[i] = temp;
        }
        sort(rem.begin(), rem.end());

        int i = 0;
        while (addr > 0 && i < n) {
            if (rem[i] != 0) {
                int r = rem[i];
                addr > rem[i] ? rem[i] = 0 : rem[i] = abs(rem[i] - addr);
                addr -= r;
            }
            i++;
        }

        int cnt = 0;
        for (int i : rem) {
            if (i == 0) {
                cnt++;
            }
        }

        return cnt;
    }
};