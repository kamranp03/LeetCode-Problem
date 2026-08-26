class Solution {
public:
    bool compare(string s1, string s2)
    {
        if(s1.length() != s2.length())
           return s1.length() < s2.length();

        return s1<s2;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int one=0;
        for(char& c:s)
        {
            if(c=='1')
               ++one;
        }

        if(one<k) return "";

        string ans=s;
        one=0;
        int start=0;
        for(int end=0;end<s.length();++end)
        {
            if(s[end]=='1') ++one;

            if(one==k)
                if(compare(s.substr(start,end - start+1),ans))
                  ans=s.substr(start,end-start+1);

            while(one==k || s[start]=='0'){
                if(s[start]=='1') --one;
                ++start;
            }      
        }
        return ans;
    }
};