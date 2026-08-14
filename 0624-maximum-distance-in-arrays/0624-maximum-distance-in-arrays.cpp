class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN= arrays[0].front();
        int MAX= arrays[0].back();

        int res=0;

        for(int i=1;i<arrays.size();i++)
        {
            int currMin= arrays[i].front();
            int currMax= arrays[i].back();

            res= max({res, abs(currMax- MIN), abs(currMin- MAX)});

            MIN= min(MIN, currMin);
            MAX= max(MAX, currMax);
        }
        return res;
    }
};