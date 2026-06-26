class Solution {
public:
    bool rotateString(string s, string goal) {
        string str= s+s;
        if(str.contains(goal))
        {
            return true;
        }
        return false;
    }
};