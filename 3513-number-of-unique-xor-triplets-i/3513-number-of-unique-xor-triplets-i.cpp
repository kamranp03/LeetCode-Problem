class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        if(n<=2) return n;
        while(ans<=n)
        {
            ans<<=1;
        }
        return ans;
    }
};