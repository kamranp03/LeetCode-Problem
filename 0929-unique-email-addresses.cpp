class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
         unordered_set<string> unique;
        
        for (string email : emails) {
            string local, domain;
            int i = 0;
            
            // Split into local and domain parts
            while (email[i] != '@') {
                local += email[i];
                i++;
            }
            domain = email.substr(i + 1);
            
            // Process local name
            string filteredLocal = "";
            for (char c : local) {
                if (c == '+') break;      // ignore everything after '+'
                if (c == '.') continue;   // ignore dots
                filteredLocal += c;
            }
            
            // Construct normalized email
            string normalized = filteredLocal + "@" + domain;
            unique.insert(normalized);
        }
        
        return unique.size();
    }
};