class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<string> st;
        
        // store all prefixes of arr1
        for(int x : arr1)
        {
            string s = to_string(x);
            string temp = "";
            
            for(char ch : s)
            {
                temp += ch;
                st.insert(temp);
            }
        }
        
        int ans = 0;
        
        // check prefixes in arr2
        for(int x : arr2)
        {
            string s = to_string(x);
            string temp = "";
            
            for(char ch : s)
            {
                temp += ch;
                
                if(st.count(temp))
                {
                    ans = max(ans, (int)temp.size());
                }
            }
        }
        
        return ans;
    }
};
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();