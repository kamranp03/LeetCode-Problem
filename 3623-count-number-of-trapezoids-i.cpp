class Solution {
public:

    int M=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
         for(auto &p:points)
         {
            int y=p[1];
            mp[y]++;
         }

         long long res=0;
         long long prevHoriLine=0;

         for( auto &it:mp)
         {
            int count=it.second;

            long long horiLine= (long long) count*(count-1)/2;

            res+=horiLine*prevHoriLine;

            prevHoriLine+=horiLine;

         }
         return res%M;
    }
};