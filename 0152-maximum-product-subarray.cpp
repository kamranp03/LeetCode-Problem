class Solution {
public:
    int maxProduct(vector<int>& a) {
         int i=0;
        int bestMax=a[0];
        int bestMin=a[0];
        int ans=a[0];
        for(i=1;i<a.size();i++)
        {
            int ch1= bestMax*a[i];
            int ch2=bestMin*a[i];
            int ch3=a[i];

            bestMax= max(ch1,max(ch2,ch3));
            bestMin= min(ch1,min(ch2,ch3));

            ans= max(ans,max(bestMax,bestMin));


        }
        return ans;
    }
};