class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        unordered_set<string> validLines = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> validCoupons;

        for (int i = 0; i < code.size(); i++) {

            // Condition 1: coupon must be active
            if (!isActive[i]) continue;

            // Condition 2: valid business line
            if (validLines.find(businessLine[i]) == validLines.end()) continue;

            // Condition 3: non-empty code with valid characters
            if (code[i].empty()) continue;

            bool isValidCode = true;
            for (char ch : code[i]) {
                if (!isalnum(ch) && ch != '_') {
                    isValidCode = false;
                    break;
                }
            }
            if (!isValidCode) continue;

            validCoupons.push_back({priority[businessLine[i]], code[i]});
        }

        // Sort by businessLine priority first, then by code lexicographically
        sort(validCoupons.begin(), validCoupons.end());

        vector<string> result;
        for (auto &p : validCoupons) {
            result.push_back(p.second);
        }

        return result;
    }
};
