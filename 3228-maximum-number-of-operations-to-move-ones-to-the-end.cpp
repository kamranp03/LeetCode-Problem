class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int res=0;
        int i=0;
        int ones=0;
        while(i<n)
        {
             if (s[i] == '0'){
                res+=ones;  
                while(i<n && s[i]=='0')
                {
                    i++;
                }   
             }       
            else{
                ones++;
                i++;
            }
                
        }
      
        return res;
    }
};