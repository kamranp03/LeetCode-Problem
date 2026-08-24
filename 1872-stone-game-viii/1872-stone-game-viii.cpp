class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        const int n=stones.size();

        partial_sum(stones.begin(),stones.end(), stones.begin());

        int ans=stones[n-1];

        for(int i=n-2;i>0;i--)
        {
            ans= max(ans, stones[i]-ans);
        }
        return ans;
    }
};