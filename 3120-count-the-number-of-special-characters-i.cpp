class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> f(58,false);
        for(char& c: word) f[c- 'A']= true;
        int cnt =0;

        for(int i=32;i<58;++i) if(f[i] && f[i-32]) ++cnt;

        return cnt;
    }
};