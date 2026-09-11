class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count{0};

        // f[i] = how many times digit i occurs
        int f[10]{0};

        for(int& d : digits)
        {
            ++f[d];
        }

        // Choose hundreds digit
        for(int i=1; i<10; i++)
        {
            // Choose tens digit
            for(int j=0; j<10; j++)
            {
                // Choose units digit
                // 0, 2, 4, 6, 8 are even
                for(int k=0; k<9; k+=2)
                {
                    count += f[i] > 0 &&
                             f[j] > (i==j) &&
                             f[k] > (i==k) + (j==k);
                }
            }
        }

        return count;
    }
};