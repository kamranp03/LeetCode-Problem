class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi=0;
        for(char ch: s)
        {
            if(ch=='(')
            {
                st.push(ch);
                int sz= st.size();
                maxi=max(maxi,sz);
            }
            if(ch==')')
            {
                st.pop();
            }
        }
            return maxi;
    }
};