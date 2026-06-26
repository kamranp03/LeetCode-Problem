class Solution {
public:
    int totalMoney(int n) {
         int weeks = n / 7;
        int days = n % 7;      
        int total = 0;

       // For week 
        for (int i = 0; i < weeks; i++) {
            total =total+ 7 * (1 + i) + 21;
        }

        //for remaining days
        for (int i = 0; i < days; i++) {
            total =total+ (1 + weeks) + i;
        }

        return total;
    }
};