class Solution {
public:
    int getSum(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+= n%10;
            n/=10;
        }
        return sum;
    }
    int getMul(int n)
    {
        int sum=1;
        while(n>0)
        {
            sum*= n%10;
            n/=10;
        }
        return sum;
    }
    bool checkDivisibility(int n) {
        int forSum=n;
        int forMul=n;

        int sum= getSum(forSum);
        int prod= getMul(forMul);

        int total=sum+prod;

        return n%total==0? true : false;
    }
};