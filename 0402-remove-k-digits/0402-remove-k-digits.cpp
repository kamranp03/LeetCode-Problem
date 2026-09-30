class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = ""; // also we can use stack here
        int n = num.length();

        for (int i = 0; i < n; i++) {
            while (res.length() > 0 && res.back() > num[i] && k > 0) // here st.top()
            {
                res.pop_back(); // st.pop();
                k--;
            }

            if (res.length() > 0 || num[i] != '0') {
                res.push_back(num[i]); // to avoid starting zero like 02000 -> 2000
            }
        }
        // there is no deleting opeartions

        while (k > 0 && res.length()>0)  {
            res.pop_back();
            k--;
        }

        if(res=="") return "0";

        return res;
    }
};