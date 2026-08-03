class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<int> res;
        int i=0,j=0;

        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }else{
                res.push_back(nums2[j]);
                j++;
            }
        }

        //remaining i
        while(i<n)
        {
            res.push_back(nums1[i]);
            i++;
        }
        //remaining j
        while(j<m)
        {
            res.push_back(nums2[j]);
            j++;
        }

        int len= res.size();
        double ans;
        if(len%2==0)
        {
            int mid= len/2;
            ans= (res[mid]+res[mid-1])/2.0;
        }else{
            ans= res[len/2];
        }
        return ans;
    }
};