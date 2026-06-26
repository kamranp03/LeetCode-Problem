class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int i=0;
        int best=a[0];
        int ans=a[0];
        for(i=1;i<a.size();i++)
        {
            int ch1= best+a[i];
            int ch2=a[i];

            best= max(ch1,ch2);
            ans= max(ans, best);


        }
        return ans;
    }
};