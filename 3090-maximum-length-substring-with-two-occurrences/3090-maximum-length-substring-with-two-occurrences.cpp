class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        vector<int> freq(26,0);
        int left=0,len=0;

        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;

            while(freq[s[i]-'a']>2)
            {
                freq[s[left]-'a']--;
                left++;
            }
            len= max(len, i-left+1);
        }
        return len;
    }
};