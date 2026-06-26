class Solution {
public:
    int numSub(string s) {
        const int M=1e9+7;
        int count =0; 
        int res=0;
        for(char i :s)
        {
            if(i=='1')
            {
                count++;
                res=(res+count)%M;
            }
            if(i=='0')
            {
                count=0;
            }
        }
        return res;
    }
};