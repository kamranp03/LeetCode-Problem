class Solution {
public:
    bool isMatch(int mp1[], int mp2[])
    {
          for(int i=0;i<26;i++)
          {
            if(mp1[i]!=mp2[i])
                return false;
          }
          return true;
    }
    bool checkInclusion(string s1, string s2) {
        int mp1[26]={0};
        for(int i=0;i<s1.size();i++)
        {
            mp1[s1[i]-'a']++;
        }

        int winSize=s1.length();

        for(int i=0;i<s2.size();i++)
        {
            int winIdx=0,idx=i;
            int mp2[26]={0};
            while(winIdx<winSize && idx<s2.size())
            {
                mp2[s2[idx]-'a']++;
                winIdx++; idx++;
            }
            if(isMatch(mp1,mp2))
            {
                return true;
            }
        }
        return false;
    }
};