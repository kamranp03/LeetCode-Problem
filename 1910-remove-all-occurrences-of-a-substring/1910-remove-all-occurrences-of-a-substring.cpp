// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         // While the substring exists in 's'
//         while (s.find(part) != string::npos) {
//             // Find its starting index and erase it
//             s.erase(s.find(part), part.length());
//         }
//         return s;
//     }
// };
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        int n = part.length();

        for (char c : s) {
            res.push_back(c); // Push current character

            // If the end of the string matches 'part', remove it
            if (res.length() >= n && res.substr(res.length() - n) == part) {
                res.erase(res.length() - n);
            }
        }

        return res;
    }
};