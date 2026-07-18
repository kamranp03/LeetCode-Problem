// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();

//         vector<int> dp(n+1);

//         dp[0]=0;
//         dp[1]=0;

//         for(int i=2;i<=n;i++)
//         {
//             dp[i]= min( dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
//         }
//         return dp[n];

//     }
// };

// optimal sc-o(1)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();


        int p1=0;
        int p2=0;
        int res=p2;
        for(int i=2;i<=n;i++)
        {
            res= min( p2+cost[i-1], p1+cost[i-2]);
            p1=p2;
            p2=res;
        }
        return res;

    }
};