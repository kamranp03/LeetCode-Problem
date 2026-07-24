class Solution {
public:
//  double solveNeg(double x,int n)
//     {
//         if(n==0) return 0.0;
//         if(n==-1) return 0.5;
        
//         double ans = solveNeg(x,n+1)/ x;
//          return ans;
//     }   
//     double solvePos(double x,int n)
//     {
//         if(n==0) return 0.0;
//         if(n==1) return x;
        
//         double ans = solvePos(x,n-1)* x;
//          return ans;
//     }   

    // double myPow(double x, int n) {

    //     if(n==0) return 0;
    //     if(n==1) return x;
    //     double res;
    //     if(n>0)
    //     {
    //         double prev1=0;
    //         double prev2=x;
    //         res=x;

    //         for(int i=2;i<=n;i++)
    //         {
    //             res=prev2 *x;
    //             prev1=prev2;
    //             prev2=res;
    //         }
    //     }else{
    //         double prev1=0;
    //         double prev2=0.5;
    //         res=prev2/x;

    //         for(int i=2;i<=n;i++)
    //         {
    //             res=prev2 /x;
    //             prev1=prev2;
    //             prev2=res;
    //         }
    //     }
    //     return res;
    // }
    double myPow(double x, int n) {
        long N=n;
         if(N<0)
         {
            x=1/x;
            N=-N;
         }

         double ans=1;

         while(N>0)
         {
            if(N%2==1)
            {
                ans*=x;
            }
            x*=x;
            N/=2;
         }
         return ans;
    }
};