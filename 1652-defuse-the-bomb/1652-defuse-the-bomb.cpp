class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);

        if (k == 0)
            return res;

        if (k > 0) {
            int sum = 0;

          
            for (int i = 1; i <= k; i++)
                sum += code[i % n];

            for (int i = 0; i < n; i++) {
                res[i] = sum;

                // Remove the old first element
                sum -= code[(i + 1) % n];

                // Add the new next element
                sum += code[(i + k + 1) % n];
            }
        }
        else {
            k = -k; 

            int sum = 0;

            
            for (int i = 1; i <= k; i++)
                sum += code[(n - i) % n];

            for (int i = 0; i < n; i++) {
                res[i] = sum;

                // Remove the old previous element
                sum -= code[(i - k + n) % n];

                // Add the new previous element
                sum += code[i];
            }
        }

        return res;
    }
};