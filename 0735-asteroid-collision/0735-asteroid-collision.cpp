class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int> st;

        for (int& a : as) {
            while (!st.empty() && a < 0 && st.top() > 0) {
                // sum is positive  we move right side , if neg the we move left
                int sum = a + st.top();

                if (sum < 0) {
                    st.pop();
                } else if (sum > 0) {
                    a = 0;
                } else { // sum=0
                    st.pop();
                    a = 0;
                }
            }

            if (a) {
                st.push(a);
            }
        }

        int s = st.size();
        vector<int> res(s);
        int i = s - 1;

        while (!st.empty()) {
            res[i] = st.top();
            st.pop();
            i--;
        }
        return res;
    }
};