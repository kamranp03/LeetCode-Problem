class Solution {
public:
    int romanToInt(string s) {
        
        int ans =0 ;
        int scndLst = 0,curr =0;

        for(char c : s)
        {
                if(c=='I') curr=1 ;
            else if(c=='V') curr=5 ;
            else if(c=='X') curr=10 ;
            else if(c=='L') curr=50 ;
            else if(c=='C') curr=100 ;
            else if(c=='D') curr=500 ;
            else if(c=='M') curr=1000;

            ans+=curr;
            if(scndLst<curr) ans-=2*scndLst;
            scndLst=curr;
        }

        return ans;
    }
};