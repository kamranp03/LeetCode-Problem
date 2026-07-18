class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        
        string s1=strs[0];
        string s2=strs[strs.size()-1];

        int i=0;

        string res="";
        while(i<s1.size() && i<s2.size())
        {
            if(s1[i]==s2[i])
            {
                res+=s1[i];
                i++;
            
            }else{
                break;
            }
           
        }
        return res;
    }
};