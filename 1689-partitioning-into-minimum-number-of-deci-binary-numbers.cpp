class Solution {
public:
    int minPartitions(string n) {
        int maxn=0;
        for(char s: n){
            maxn = max(maxn, s - '0');
        }
        return maxn;
    }
};