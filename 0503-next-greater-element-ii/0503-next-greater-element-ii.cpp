class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();

        vector<int> res(n,-1);
        stack<int> st;
        
        for(int i=2*n-1;i>=0;i--)
        {
            while(st.size()> 0 && nums[st.top()]<= nums[i%n])
                st.pop();

            res[i%n]= st.empty() ? -1 : nums[st.top()];
            st.push(i%n);     
        }
        return res;
    }
};