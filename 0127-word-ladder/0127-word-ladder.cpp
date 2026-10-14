class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> f;

        for(int i=0;i<wordList.size();i++)
        {
            f[wordList[i]]=1;
        }

        if(f.find(beginWord)==f.end())
        {
            f[beginWord]=1;
        }
        if(f.find(endWord)==f.end())
            return 0;

        queue<pair<string,int>> q;

        q.push({beginWord,1});
        f.erase(beginWord);

        while(!q.empty())
        {
            string s= q.front().first;
            int val= q.front().second; 

            q.pop();

            if(s==endWord)
                return val;

            for(int i=0;i<s.length();i++)
            {
                int c= s[i];

                for(int j=97;j<=122;j++) // lowercase askii value
                {
                    if(c==j) continue;

                    s[i]=j;

                    if(f.find(s)!= f.end())
                    {
                        q.push({s,val+1});
                        f.erase(s);
                    }
                }
                s[i]=c;
            }
        }
        return 0;
    }
};