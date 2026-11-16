class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string temp = ""; // string for evry devide iteration
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0; // we want sum of k number on evry iterration
                for (int j = i; j < min(i + k, (int)s.length());
                     ++j) {            // min() for avoid out of bound
                    sum += s[j] - '0'; // add current number in sum
                }
                temp += to_string(
                    sum); // add that sum in temp  as string for next iteration
            }
            s = temp;
        }
        return s;
    }
};