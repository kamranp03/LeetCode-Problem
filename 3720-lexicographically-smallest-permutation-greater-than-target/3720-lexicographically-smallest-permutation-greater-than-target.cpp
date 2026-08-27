class Solution {
public:
    string getMinString(const int* freq)
    {
        string res;
        for(int i=0;i<26;++i)
        {
            res.append(freq[i],'a'+i);
        }
        return res;
    }
    string lexGreaterPermutation(string s, string target) {
        int freq[26]{0};

        for(char c: s)
        {
            freq[c-'a']++;
        }
        for(char c:target)
        {
            freq[c-'a']--;
        }

        for(int i=s.size()-1;i>=0;--i)
        {
            int b=target[i]-'a';
            freq[b]++;

            if(*min_element(freq,freq+26)<0) continue;

            for(int j=b+1;j<26;++j)
            {
                if(freq[j]){
                    freq[j]--;
                    target[i]='a'+j;
                    target.resize(i+1);
                    return target+ getMinString(freq);
                }
            }
        }
        return "";
    }
};