class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int orignal=x;
         int rem;
         long long rev=0;
        while(x!=0)
        {
            rem=x%10;
            rev=rev*10+rem;
            if (rev > INT_MAX || rev < INT_MIN)
                return 0;
            x=x/10;
        }
       return (rev==orignal);
    }
};