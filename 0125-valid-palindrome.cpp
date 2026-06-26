class Solution {
public:
    bool isPalindrome(string s) {

        string ss;

        for (char ch : s) {
            if (isalnum(ch)) {
                ss.push_back(tolower(ch));
            }
        }

        int i = 0;
        int j = ss.size() - 1;

        while (i < j) {
            if (ss[i] != ss[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};