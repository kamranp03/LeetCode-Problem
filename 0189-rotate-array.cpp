class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            int newp= (i+k)%n;
            res[newp]= nums[i];
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=res[i];
        }
    }
};