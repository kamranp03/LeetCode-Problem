class Solution {
public:
int findFact(int num)
{
    int divisor=0;
    int sum=0;

    for(int fact=1;fact*fact<=num;fact++)
    {
        if(num %fact==0)
        {
        int other=num/fact;

        if(other==fact)
        {
            divisor+=1;
            sum+=fact;
        }else{
            divisor+=2;
            sum+=(other+fact);
        }
        }
        if(divisor>4)
        {
            return 0;
        }
    }

    return divisor ==4 ? sum:0;
}
    int sumFourDivisors(vector<int>& nums) {
        int res=0;

        for(int &num:nums)
        {
          res+=findFact(num);
        }

        return res;
    }
};