class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        vector<int> freq(n + 1, 0);

        for (int x : citations) {
            if (x >= n)
                freq[n]++;
            else
                freq[x]++;
        }

        int count = 0;

        
        for (int h = n; h >= 0; h--) {
            count += freq[h];

            if (count >= h)
                return h;
        }

        return 0;
    }
};