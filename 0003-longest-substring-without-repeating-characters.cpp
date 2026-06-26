class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,h=0;
        int res=INT_MIN;
        unordered_map<char,int> mp;

        for(h=0;h<n;h++)
        {
            mp[s[h]]++;
            int k= h-l+1;

            while(mp.size()<k)
            {
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
                k=h-l+1;
            }

            k=h-l+1;
            res= max(res,k);
        }
        if(res==INT_MIN)
          return 0;

        return res;  
    }
};