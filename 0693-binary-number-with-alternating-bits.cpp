class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int res = n ^ (n>>1 );
        
        return (res &(res+1)) == 0;
            }
};