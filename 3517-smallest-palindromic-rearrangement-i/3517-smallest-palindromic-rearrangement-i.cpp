// class Solution {
// public:
//     string smallestPalindrome(string s) {
//         if (s.length() == 3 || s.length() == 1)
//             return s;
//         if (s.length() == 2) {
//             reverse(s.begin(), s.end());
//             return s;
//         }
//         sort(s.begin(), s.end());

//         int i = 0;
//         int j = s.size() - 1;

//         while (i < j) {
//             if (s[i] != s[j]) {
//                 char ch = s[i];

//                 s.erase(s.begin() + i);

//                 s.insert(s.begin() + j, ch);

//                 i++;
//                 j--;
//             } else {
//                 i++;
//                 j--;
//             }
//         }

//         return s;
//     }
// };
class Solution {
public:
    string smallestPalindrome(string s) {
       int n=s.length();
       int part= n/2;

       sort(s.begin(), s.begin()+part);

       for(int i=0;i<part;i++)
       {
        s[n-i-1]=s[i];
       }
       return s;
    }
};