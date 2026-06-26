class Solution {
public:
    int sqr(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int d = n % 10;
            n = n / 10;
            sum += d * d;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        while (true)
        {
            slow = sqr(slow);          
            fast = sqr(sqr(fast));     

            if (fast == 1) return true;

            if (slow == fast) return false;
        }
    }
};