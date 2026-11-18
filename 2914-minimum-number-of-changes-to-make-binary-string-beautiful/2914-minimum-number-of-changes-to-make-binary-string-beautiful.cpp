class Solution {
public:
    int minChanges(string s) {
        int ans=0;

        // divide substring in size of 2 
        for(int i=0;i<s.length();i+=2)
        {
            if(s[i]=='1' && s[i+1]=='1') continue;
            if(s[i]=='0' && s[i+1]=='0') continue;

            //not same change req
            ans++;
        }
        return ans;
    }
};