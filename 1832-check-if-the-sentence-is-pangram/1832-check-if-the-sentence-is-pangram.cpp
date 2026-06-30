class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> vis(26);
        if(sentence.size()<26)
            return false;

        for(char ch: sentence)
        {
            vis[ch-'a']++;
        }
        for(int a: vis){
            if(a==0)
                return false;
        }
        return true;
    }
};