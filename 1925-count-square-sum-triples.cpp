class Solution {
public:
    int countTriples(int n) {
        int c=0;

        for(int a=1;a<=n;a++)
        {
            for(int b=a+1;b<=n;b++)
            {
                int s=(a*a)+(b*b);
                int x=sqrt(s);

                if(x*x==s && x<=n)
                c+=2;
            }
        
        }
        return c;
    }
};