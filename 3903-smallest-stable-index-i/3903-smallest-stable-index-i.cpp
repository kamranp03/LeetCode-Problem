class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int stbIdx;
        int minStbVal = INT_MAX;
        int minIdx = -1;

        // for loop 
        for(int i=0;i<nums.size();i++){
            int max = *max_element(nums.begin(),nums.begin()+i);
            int minimum = *min_element(nums.begin()+i,nums.end());
            int sum = max - minimum;
            if(sum <= k && sum < minStbVal){
                minStbVal = min(sum,minStbVal);
                return i;
            }
        }

        return minIdx;
    }
};