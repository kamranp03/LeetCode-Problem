class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> st;
        vector<int> res(seq.length(), -1);
        for (int i = 0; i < seq.length(); i++) {
            if (seq[i] == '(') {
                st.push(seq[i]);
                res[i] = st.size() % 2;
            } else {

                res[i] = st.size() % 2;
                st.pop();
            }
        }
        return res;
    }
};