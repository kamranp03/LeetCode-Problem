class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // find overlap - same number of both item
        long long overlap = min(need1, need2);
        
        // mini cost for both
        long long minCostForBoth = min((long long)costBoth, (long long)cost1 + cost2);
        
        // buy same item with minimum cost
        long long ans = overlap * minCostForBoth;
        
        // check which item remain and buy 
        // for need1
        if (need1 > overlap) {
            long long rem1 = need1 - overlap;
            ans += rem1 * min((long long)cost1, (long long)costBoth);
        }
        
        // for need 2
        if (need2 > overlap) {
            long long rem2 = need2 - overlap;
            ans += rem2 * min((long long)cost2, (long long)costBoth);
        }
        
        return ans;
    }
};