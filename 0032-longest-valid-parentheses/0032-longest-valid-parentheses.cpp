// Approach 1-> recursive Tc=O(n) sc= O(N)
/*
    int n;
    int maxi;
    void solve(string& s, int i, stack<int>& st) {
        if (i == n) {
            return;
        }

        if (s[i] == '(') {
            st.push(i);
            solve(s, i + 1, st);
        }
        else
        {
            st.pop();
            if(st.empty())
            {
                st.push(i);// invalid
            }else{
                maxi= max(maxi, i- st.top());
            }
            solve(s, i + 1, st);
        }
        return;
    }
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        n = s.length();
        maxi = 0;

        solve(s, 0, st);

        return maxi;
    }
    */
// Appraoch 2- iterative
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // store idx
        st.push(-1); // for futher calculation
        int n = s.length();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) { //  invadil ")"
                    st.push(i);
                } else {        // valid ")"
                    maxi = max(maxi, i - st.top());
                }
            }
        }
        return maxi;
    }
    };