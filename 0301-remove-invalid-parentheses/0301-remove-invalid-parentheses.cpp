class Solution {
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};

        queue<string> q;
        unordered_set<string> visited;
        
        q.push(s);
        visited.insert(s);
        
        bool found = false;

        while (!q.empty()) {
            int levelSize = q.size();
            unordered_set<string> levelVisited; // to avoid duplicates in the same level
            
            for (int i = 0; i < levelSize; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }

                if (found) continue; // If we found valid strings at this depth, don't remove more

                // Generate all possible states by removing one parenthesis
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string next = curr.substr(0, j) + curr.substr(j + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            
            if (found) break; // Minimum removals reached, stop BFS
        }

        return result;
    }
};
//     void validAdd(string& s,int i, vector<string>& res)
//     {
//         string temp;

//         for(int j=0;j<s.length();j++)
//         {
//             if(j==i) continue;

//             temp.push_back(s[j]);
//         }

//         res.push_back(temp);
//     }
//     void check(string s, int i, vector<string>& res)
//     {
//         stack<char> st;

//         for(int k=0;k<s.length();k++)
//         {
//             if(k==i) continue;

//             if(s[k]=='(') st.push(s[k]);
//             else if(!st.empty() && s[k]==')')
//                 st.pop();
//             else if(st.empty() && s[i]==')')
//                  return;
//         }
//         if(st.empty()) validAdd(s,i,res);
//     }
//     vector<string> removeInvalidParentheses(string s) {
//         vector<string> res;

//         for(int i=0;i<s.length();i++)
//         {
//             if(s[i]=='(' || s[i]==')')
//                 check(s,i,res);
//         }

//         return res;
//     }
// };
//     vector<string> removeInvalidParentheses(string s) {
//         vector<string> res;
//         int count=0;
//         string temp;

//         for(int i=0;i<s.length();i++)
//         {
//             if(s[i]=='(') {
//                 count++;
//                 temp.push_back(s[i]);
//             }else if(count==0 && s[i]==')'){
//                 continue;
//             }else if(s[i]==')'){
//                 temp.push_back(s[i]);
//                 count--;
//             }
//         }

//         if(count==0) res.push_back(temp);

//         count=0;
//         temp="";

//          for(int i=s.length()-1;i>=0;i--)
//         {
//             if(s[i]=='(') {
//                 count--;
//                 temp.push_back(s[i]);
//             }else if(count==0 && s[i]=='('){
//                 continue;
//             }else if(s[i]==')'){
//                 temp.push_back(s[i]);
//                 count++;
//             }
//         }
//         if(count==0) res.push_back(temp);

//         return res;
//     }
// };

