class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int lmax=0,rmax=0;

        int ans =0;
        while(i<j)
        {
            lmax=max(lmax, height[i]);
            rmax= max(rmax,height[j]);

            if(lmax<rmax)
            {
                ans+= lmax-height[i];
                i++;
            }else{
                ans+= rmax-height[j];
                j--;
            }
        }
        return ans;
    }
};