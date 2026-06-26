class Solution {
public:
    int M=1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> i;
        unordered_map<int,int> j;

        int res=0;

        for(int &num: nums)
        {
            if(num%2==0)
            {
                res=(res+j[num/2])%M;

            }

            j[num]=(j[num]+i[num*2])%M;

            i[num]++;

        }
        return res;
    }
};