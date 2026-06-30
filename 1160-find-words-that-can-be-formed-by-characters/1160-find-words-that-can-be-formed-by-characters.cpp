class Solution {
public:

    bool isAvail(string s, unordered_map<char,int>& mp)
    {
        unordered_map<char,int> temp = mp;

        for(char ch : s)
        {
            if(temp[ch] == 0)
                return false;

            temp[ch]--;
        }

        return true;
    }

    int countCharacters(vector<string>& words, string chars) {

        unordered_map<char,int> mp;

        for(char ch : chars)
        {
            mp[ch]++;
        }

        int ans = 0;

        for(string word : words)
        {
            if(isAvail(word, mp))
            {
                ans += word.size();
            }
        }

        return ans;
    }
};