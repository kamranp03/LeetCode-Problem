class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);

        for(char ch: s)
           freq[ch - 'a']++;

        for(char ch : t)
           freq[ch -'a']--;

        int step=0;
        for(int cnt: freq){
            if(cnt>0)
               step+=cnt;
        }
        return step;
    }
};