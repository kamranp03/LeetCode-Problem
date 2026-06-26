class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();

        vector<pair<int,int>> ind(26,{-1,-1});

        for(int i=0;i<n;i++)
        {
            char ch=s[i];

            int idx=ch-'a';

            if(ind[idx].first==-1)
            {
                ind[idx].first=i;
            }
            ind[idx].second=i;
        }

        int res=0;

        for(int i=0;i<26;i++)
        {

            int left=ind[i].first;
            int right=ind[i].second;

            if(left==-1)
            {
                continue;
            }

            unordered_set<char> st;

            for( int mid=left+1;mid<=right-1;mid++)
            {
                st.insert(s[mid]);
            }
            res+=st.size();

        }
        return res;
        
    }
};