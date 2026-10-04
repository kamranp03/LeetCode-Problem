class Solution {
public:
    bool checkValidString(string s) {
        int minopn = 0; // if start consider as close
        int maxopn = 0; // if star the conisder as open

        for (char c : s) {
            if (c == '(') {
                minopn++;
                maxopn++;
            } else if (c == ')') {
                minopn--;
                maxopn--;
            } else {      // star
                minopn--; // consider )
                maxopn++; // consider (
            }

            if (maxopn < 0) {
                // extra close
                return false;
            }

            if (minopn < 0) {
                // more starts there
                minopn = 0;
            }
        }

        return minopn == 0;
    }
};
