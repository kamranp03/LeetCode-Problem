class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int neg=0;
     

        for(auto& ch:grid)
        {
            for(int i=0;i<ch.size();i++)
            {
                if(ch[i]<0)
                {
                    neg++;
                }
            }
        }
        return neg;
    }
};
