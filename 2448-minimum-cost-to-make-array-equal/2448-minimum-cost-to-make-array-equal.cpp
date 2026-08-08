class Solution {
public:
    typedef long long ll;
    ll findCost(vector<int>& nums, vector<int>& cost, int target)
    {
        ll res=0;
        for(int i=0;i<nums.size();i++)
        {
            res+= (ll) abs(nums[i]-target)* cost[i];
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll ans=INT_MAX;

        int l= *min_element(nums.begin(),nums.end());
        int r= *max_element(nums.begin(), nums.end());

        while(l<=r)
        {
            int mid= l+(r-l)/2;

            ll cost1= findCost(nums,cost,mid);
            ll cost2= findCost(nums,cost,mid+1);

            ans= min(cost1,cost2);

            if(cost2>cost1)
            {
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans==INT_MAX ? 0: ans;
    }
};