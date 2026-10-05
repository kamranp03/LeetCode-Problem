class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        unordered_map<char,int> mp;

        for(char c: s)
        {
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;

        for(auto& it: mp)
        {
            pq.push({it.second,it.first});
        }
        int sz= pq.top().first;

        if(sz > (s.length()+1) /2) return "";
        string res;

        while(!pq.empty())
        {
            int freq= pq.top().first;
            char ch= pq.top().second;
            freq--;
            pq.pop();
            res+=ch;

            if(!pq.empty()){
                int f= pq.top().first;
                char c= pq.top().second;
                f--;
                res+=c;
                pq.pop();
                if(f>0){
                    pq.push({f,c});
                }
            }
            if(freq>0) pq.push({freq,ch});

            
        }
        return res;
    }
};