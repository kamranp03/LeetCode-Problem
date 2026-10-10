class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int gap=0; // largets gap
        vector<int> bucket; // for all gaps;
        int n= nums1.size();
        long long k= k1+k2; // total k ops

        // fib=nd largest gap and initialize bucket with that size
        for(int i=0;i<n;i++)
        {
            gap= max(gap, abs(nums1[i]-nums2[i]));
        }
        bucket.assign(gap+1,0); // 
        // add all counts of gap on there location
        for(int i=0;i<n;i++)
        {
            bucket[abs(nums1[i]-nums2[i])]++;
        }

        //from max gap reduce k bcz higher value reduce give less cost
        for(int i=gap; i>0 && k>0; i--)
        {
            // check if k small than that gap freq
            long long take= min((long long)bucket[i],k);

            bucket[i]-=take;
            bucket[i-1]+= take;

            k-= take;
        } 

        long long ans=0;
        // calculate cost
        for(int i=1;i<=gap;i++)
        {
            ans+= 1LL * bucket[i] *i*i;
        }
        return ans;
    }
};