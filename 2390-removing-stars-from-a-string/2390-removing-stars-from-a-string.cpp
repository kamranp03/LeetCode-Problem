class Solution {
public:
    string removeStars(string s) {
        string res;

        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
            if(st.size()>0 && s[i]=='*')
                st.pop();
            else
                st.push(s[i]);    
        }

        while(st.size()>0)
        {
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};